from django.contrib import admin
from.models import advertise

from.models import Slocation
from .models import Registration

# Register your models here.

admin.site.register(advertise)
admin.site.register(Slocation)
admin.site.register(Registration)

