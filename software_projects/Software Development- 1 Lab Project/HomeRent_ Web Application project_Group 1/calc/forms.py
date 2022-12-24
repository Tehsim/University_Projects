from django import forms
from django.utils.timezone import now
from.models import advertise
from.models import Slocation
"""
from django.forms import ModelForm
from django.contrib.auth.forms import UserCreationForm
from django import forms
from django.contrib.auth.models import  User


from .models import Order


class OrderForm(ModelForm):
    class Meta:
        model = Order
        fields = '_all_'


class CreateUserForm(UserCreationForm):
    class Meta:
        model = User
        fields = ['username', 'email', 'password1', 'password2']
"""

# class SlocationForm(forms.ModelForm):
# class Meta:
#   model = Slocation
#  fields = ['division','city', 'locality']


def get_division_choices():
    # you place some logic here
    return Slocation.objects.values_list("division", "division").distinct()


def get_city_choices():
    # you place some logic here
    return Slocation.objects.values_list("city", "city").distinct()


def get_locality_choices():
    # you place some logic here
    return Slocation.objects.values_list("locality", "locality").distinct()


class DateInput(forms.DateInput):
    input_type = 'date'


class advertiseForm(forms.ModelForm):  # this is for searching
    CATEGORY_CHOICES = (
        ("Residential", "Residential"),
        ("Commercial", "Commercial")
    )
    AVAILABLE_CHOICES = (
        ("YES", "YES"),
        ("NO", "NO")
    )

    ad_catagory = forms.ChoiceField(choices=CATEGORY_CHOICES, widget=forms.Select(
        attrs={'class': 'form-control select'}))
    available = forms.ChoiceField(choices=AVAILABLE_CHOICES, widget=forms.Select(
        attrs={'class': 'form-control select'}))

    # post_date_time = forms.DateTimeField(default=get_now())
    # post_date_time = forms.DateField(widget=SelectDateWidget())
    post_date_time = forms.DateField(
        widget=DateInput(attrs={'class': 'form-control'}))

    division = forms.ChoiceField(choices=get_division_choices(
    ), widget=forms.Select(attrs={'class': 'form-control select'}))

    city = forms.ChoiceField(choices=get_city_choices(), widget=forms.Select(
        attrs={'class': 'form-control select'}))

    locality = forms.ChoiceField(choices=get_locality_choices(
    ), widget=forms.Select(attrs={'class': 'form-control select'}))

    class Meta:
        model = advertise
        fields = ['ad_title', 'ad_detail', 'ad_catagory', 'post_date_time','available', 'size', 'img_1', 'user_name',
                  'contact_no', 'email', 'division',  'city', 'locality', 'address', 'deposit_tk', 'monthly_rent']

        # , 'img_2', 'img_3',
        widgets = {
            'ad_title': forms.TextInput(attrs={'class': 'form-control'}),
            'ad_detail': forms.TextInput(attrs={'class': 'form-control'}),
            # 'ad_catagory': forms.ChoiceField(attrs={'class': 'form-control select'}),
            # 'post_date_time': forms.DateTimeInput(attrs={'class': 'form-control'}),
            # 'post_date_time': forms.DateInput(attrs={'class': 'form-control'}),

            # 'available': forms.TextInput(attrs={'class': 'form-control'}),
            'size': forms.TextInput(attrs={'class': 'form-control'}),
            'img_1': forms.FileInput(attrs={'class': 'form-control'}),
            # 'img_2': forms.FileInput(attrs={'class': 'form-control'}),
            # 'img_3': forms.FileInput(attrs={'class': 'form-control'}),
            'user_name': forms.HiddenInput(),
            'contact_no': forms.TextInput(attrs={'class': 'form-control'}),
            'email': forms.HiddenInput(),
            'division': forms.TextInput(attrs={'class': 'form-control'}),
            'city': forms.TextInput(attrs={'class': 'form-control'}),
            'locality': forms.TextInput(attrs={'class': 'form-control'}),
            'address': forms.TextInput(attrs={'class': 'form-control'}),
            'deposit_tk': forms.TextInput(attrs={'class': 'form-control'}),
            'monthly_rent': forms.TextInput(attrs={'class': 'form-control'})
        }


class ContactForm(forms.Form):
    name = forms.CharField(max_length=50, widget=forms.TextInput(
        attrs={'class': 'form-control'}))
    email_address = forms.EmailField(widget=forms.TextInput(
        attrs={'class': 'form-control'}))
    message = forms.CharField(max_length=200, widget=forms.TextInput(
        attrs={'class': 'form-control'}))
