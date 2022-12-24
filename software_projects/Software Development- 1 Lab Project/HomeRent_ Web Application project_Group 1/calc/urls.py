from django.urls import path
from.import views
#app_name= 'calc'

urlpatterns = [

    path('', views.homeView, name='home'),  #
    path('home/', views.homeView, name='home'),  # here 'home'=url name

    # path("homelogin", views.homeloginview, name='front'),
    # path("frontlogin", views.frontlogin, name='front'),
    path('profile', views.profileView, name='profile'),  # here 'profile'=url name
    path('signin', views.signinView, name='signin'),  # here 'signin'=url name
    path('signup', views.signupView, name='signup'),  # here 'signup'=url name
    path('logout', views.logout, name='logout'),

    # here 'contact'=url name
    path('contact/', views.contactView, name='contact'),
    path('postadver', views.PostAdverCreate, name="postadvertise"),
    # this is for showing all post list
    path('postadverlist', views.PostAdverListView, name="postadvertiselist"),
    path('<int:id>/', views.PostAdverUpdate, name="update"),
    path('delete/<int:id>', views.Delete),

    # path('register/',views.registerPage, name="register"), #here 'register'=url name
    # path('login/',views.loginPage, name="login"), #here 'login'=url name
]
