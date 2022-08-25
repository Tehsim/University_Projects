# from django.forms import inlineformset_factory
# from django.contrib.auth.forms import UserCreationForm
# from.forms import advertiseForm,advertiseSearchForm,SlocationForm
from datetime import datetime
from django.http import HttpResponse
from django.core.mail import send_mail, BadHeaderError
from calc.forms import advertiseForm
from .forms import ContactForm
from calc.models import Registration
from django.shortcuts import get_object_or_404, render, redirect
from django.contrib import messages
from django.db.models import Q
from.models import Slocation


from.models import advertise


# Create your views here.   # we can comment after selecting the line , ctrl+k then ctrl+c    and uncomment ,ctrl+k and ctrl+u

"""from .models import*
from .forms import OrderForm, CreateUserForm
from .filters import OrderFilter """


def homeView(request):

    # messages.info(request, '')
    # load division dropdown list
    division_list = Slocation.objects.values('division').distinct()
    # load city dropdown list
    city_list = Slocation.objects.values('city').distinct()
    # load locality dropdown list
    locality_list = Slocation.objects.values('locality').distinct()

    # put an object variable (locationList) with all dropdown list
    locationList = {'divisionList': division_list,
                    'cityList':  city_list, 'localityList': locality_list}

    # get user selected division - dropdown value
    param_division = request.GET.get('division')
    # get user selected city - dropdown value
    param_city = request.GET.get('city')
    # get user selected locality - dropdown value
    param_locality = request.GET.get('locality')

    # put an object variable (query) with all selected dropdown values
    query = {'division': param_division,
             'city': param_city, 'locality': param_locality}

    # hold logged in user session value
    session_user = request.session.get('user_name')

    msg = ""

    # validation check :  all fields variable are not empty
    if(param_division and param_city and param_locality):
        results = advertise.objects.filter(Q(division=param_division) and Q(city=param_city) and Q(locality=param_locality))
    elif(param_division and param_city):
        results = advertise.objects.filter(Q(division=param_division) and Q(city=param_city))
    elif(param_division and param_locality):
        results = advertise.objects.filter(Q(division=param_division) and Q(locality=param_locality))
    elif(param_city and param_locality):
        results = advertise.objects.filter(Q(city=param_city) and Q(locality=param_locality))
    elif(param_division):
        results = advertise.objects.filter(Q(division=param_division))
    elif(param_city):
        results = advertise.objects.filter(Q(city=param_city))
    elif(param_locality):
        results = advertise.objects.filter(Q(locality=param_locality))

        #### if (param_division or param_city or param_locality):
        #### queryset = advertise.objects.all()
        # (Q(text__icontains=query))
        # I assume "text" is a field in your model
        # i.e., text = model.TextField()
        # Use | if searching multiple fields, i.e.,
        # queryset = (Q(text__icontains=query))|(Q(other__icontains=query))
        # .filter(division=param_division, city=param_city, locality =param_locality)
        # Q(division=param_division) | Q(city=param_city) | Q(locality =param_locality)
        # if(param_division and param_city and param_locality):
        #### results = advertise.objects.filter(Q(division=param_division) or Q(city=param_city) or Q(locality=param_locality))
        # else if(param_division and param_city and param_locality):
        #     results = advertise.objects.filter(Q(division=param_division) | Q(city=param_city) | Q(locality=param_locality))

        # results = advertise.objects.filter((Q(division=param_division) and Q(available="YES")) | (Q(
        #     city=param_city) and Q(available="YES")) | (Q(locality=param_locality) and Q(available="YES")))

    else:
        results = []
        # messages.info(request, 'Please select at least one field!')
        msg = 'Please select at least one field!'
    return render(request, 'index.html', {'results': results, 'query': query, 'location': locationList, 'user': session_user, "msg": msg })

    # You can also set context = {'results':results, 'query':query} after
    # the else: (same indentation as return statement), and
    # use render(request, 'home.html', context) if you prefer.

    # def front(request):
    #     return render(request,'front.html')

    # def loginview(request):
    #     return render(request,'signin.html')

    # def frontlogin(request):
    #     return render(request,'frontlogin.html')


def contactView(request):
    # hold logged in user session value
    session_user = request.session.get('user_name')
    if request.method == 'POST':
        form = ContactForm(request.POST)
        if form.is_valid():
            subject = "Website Inquiry"
            body = {
                'name': form.cleaned_data['name'],
                'email': form.cleaned_data['email_address'],
                'message': form.cleaned_data['message'],
            }
            message = "\n".join(body.values())

            try:
                send_mail(subject, message, 'admin@example.com',
                          ['admin@example.com'])
            except BadHeaderError:
                return HttpResponse('Invalid header found.')
            return redirect("home")

    form = ContactForm()
    return render(request, "contact.html", {'form': form})


def signinView(request):
    msg = ""
    if request.method == 'POST':
        try:
            Userdetails = Registration.objects.get(
                email=request.POST['email'], password=request.POST['password'])
            request.session['email'] = Userdetails.email
            request.session['user_name'] = Userdetails.full_name
            return redirect("home")
        except Registration.DoesNotExist as e:
            messages.error(request, 'Invalid...!')
            msg = 'Invalid credentials!'
    return render(request, 'signin.html', { "msg": msg })


def signupView(request):
    # hold logged in user session value
    session_user = request.session.get('user_name')
    msg = ""
    if request.method == 'GET':
        # load city dropdown list
        city_list = Slocation.objects.values('city').distinct()
        # load locality dropdown list
        locality_list = Slocation.objects.values('locality').distinct()
        return render(request, 'signup.html', {'city_data': city_list, 'locality_data': locality_list, "msg": msg})
    else:
        postData = request.POST
        full_name = postData.get('fullName')
        email = postData.get('email')
        password = postData.get('password')
        contact_number = postData.get('contactNum')
        area = postData.get('area')
        address = postData.get('address')

        # check exist email
        isEmailExist = Registration.objects.filter(Q(email=email)).first()
        if(isEmailExist):
            msg = "Email already exist!"
            return render(request, 'signup.html', { "msg": msg })

        # check for password
        if len(password) < 6:
            messages.error(
                request, "Password length should be at least 6 characters")
            msg = "Password length should be at least 6 characters"
            return render(request, 'signup.html', { "msg": msg })

        if not any(char.isdigit() for char in password):
            messages.error(
                request, "Password should have at least one numeral")
            msg = "Password should have at least one numeral"
            return render(request, 'signup.html', { "msg": msg })

        if not any(char.isupper() for char in password):
            messages.error(
                request, "Password should have at least one uppercase letter")
            msg = "Password should have at least one uppercase letter"
            return render(request, 'signup.html', { "msg": msg })

        if not any(char.islower() for char in password):
            messages.error(
                request, "Password should have at least one lowercase letter")
            msg = "Password should have at least one lowercase letter"
            return render(request, 'signup.html', { "msg": msg })

        Registration(full_name=full_name,
                     email=email,
                     password=password,
                     contact_number=contact_number,
                     area=area,
                     address=address).save()

        messages.success(request, "Sign up Successfully")
        msg = "Signup successfully completed!"
        return render(request, 'signup.html', { "msg": msg })


def logout(request):
    # hold logged in user session value
    session_user = request.session.get('user_name')
    if session_user:
        try:
            del request.session['email']
            del request.session['user_name']
        except:
            return redirect("/signin")
        return redirect("/signin")
    else:
        return render(request, 'index.html')


def PostAdverCreate(request):
    # hold logged in user session value
    session_user = request.session.get('user_name')
    session_user_email = request.session.get('email')
    context = {}
    msg = ""
    if session_user:
        reqObj = request.POST
        # set to mutable
        reqObj._mutable = True

        reqObj["user_name"] = session_user
        reqObj["email"] = session_user_email
        # set to mutable
        reqObj._mutable = False

        form = advertiseForm(reqObj)
        
        if form.is_valid():
            form.save()
            form = advertiseForm()
            return redirect("/postadverlist")

        msg = "Please make sure all fields are filled in correctly."
        context['form'] = form
        context['user'] = session_user
        context['msg'] = msg
        return render(request, 'postad.html', context)
    else:
        msg = "Session expired!"
        context['form'] = advertiseForm()
        context['user'] = ""
        context['msg'] = msg
        return render(request, 'signin.html', context)

    # form = advertiseForm
    # if request.method == 'POST':
    #     forms = advertiseForm(request.POST or None)
    #     if forms.is_valid():
    #         forms.save()
    #         messages.success(request, 'Form has been submitted.')
    #         return redirect('/postadverlist')

    # return render(request, 'postad.html', {'form': form})

def profileView(request):
    # session_user = request.session.get('user_name')
    session_user_email = request.session.get('email')
    context = {}
    msg = ""
    if session_user_email:
        results = Registration.objects.filter(Q(email=session_user_email)).first()
        context['msg'] = msg
        context['profile_data'] = results
        return render(request, 'profile.html', context)
    else:
        msg = "Session expired!"
        context['msg'] = msg
        context['profile_data'] = Registration()
        return render(request, 'profile.html', context)

def PostAdverListView(request):
    # hold logged in user session value
    session_user = request.session.get('user_name')
    if session_user:
        # Advertise = advertise.objects.all()

        logged_user_email = request.session.get('email')

        Advertise = advertise.objects.filter(Q(email=logged_user_email))

        return render(request, "postadlist.html", {'Advertise': Advertise})
    else:
        return render(request, 'signin.html', {'Advertise': []})


def PostAdverEditView(request, id):
    # hold logged in user session value
    session_user = request.session.get('user_name')
    if session_user:
        ADvertise = advertise.objects.get(id=id)

        return render(request, 'postedit.html', {'ADvertise': ADvertise})
    else:
        return render(request, 'signin.html')


def PostAdverUpdate(request, id):
    # hold logged in user session value
    session_user = request.session.get('user_name')
    context = {}
    if session_user:
        if request.method == 'POST':
            advertiseUpdate = advertise.objects.get(pk=id)
            form = advertiseForm(request.POST, instance=advertiseUpdate)
            if form.is_valid():
                form.save()
                return redirect("/postadverlist")
        else:
            advertiseUpdate = advertise.objects.get(pk=id)
            form = advertiseForm(instance=advertiseUpdate)

        context['form'] = form
        return render(request, 'postedit.html', context)
    else:
        return render(request, 'signin.html')


def Delete(request, id):
    # hold logged in user session value
    session_user = request.session.get('user_name')
    if session_user:
        advertiseDel = advertise.objects.get(id=id)
        advertiseDel.delete()
        return redirect("/postadverlist")
    else:
        return render(request, 'index.html')
