from django.db import models
from django.utils import timezone
from django.utils.timezone import now


# Create your models here.

class Registration(models.Model):
    full_name = models.CharField(max_length=50)
    email = models.EmailField()
    password = models.CharField(max_length=16)
    contact_number = models.CharField(max_length=15)
    area = models.CharField(max_length=50)
    address = models.CharField(max_length=60)

    class Meta:
        db_table = "registration"


class Slocation(models.Model):
    # i deleted this field
    division = models.CharField(max_length=100)
    city = models.CharField(max_length=100)
    locality = models.CharField(max_length=100)  # area
    # i also deleted this field


# class Country(models.Model):
#     name = models.CharField(max_length=30)

#     def __str__(self):
#         return self.name

# class City(models.Model):
#     country = models.ForeignKey(Country, on_delete=models.CASCADE)
#     name = models.CharField(max_length=30)

#     def __str__(self):
#         return self.name

# class Category(models.Model):
#     catName = models.CharField(max_length=100)

class advertise(models.Model):
    ad_title = models.CharField(max_length=100)
    ad_detail = models.CharField(max_length=2000)
    ad_catagory = models.CharField(max_length=100)  # area
    ad_type = models.CharField(max_length=100, default=False)
    post_date_time = models.DateTimeField(default=now, blank=True)
    available = models.CharField(max_length=100,default='YES')
    size = models.CharField(max_length=100)
    img_1 = models.ImageField(upload_to="images", blank=True, null=True)
    img_2 = models.ImageField(upload_to="images", blank=True, null=True)
    img_3 = models.ImageField(upload_to="images", blank=True, null=True, default=False)
    img_4 = models.ImageField(upload_to="images", blank=True, null=True, default=False)
    img_5 = models.ImageField(upload_to="images", blank=True, null=True, default=False)
    # it's come from registration model/table
    user_id = models.IntegerField(default=False)
    user_name = models.CharField(max_length=100)
    contact_no = models.IntegerField()
    email = models.CharField(max_length=100)
    division = models.CharField(max_length=100)
    city = models.CharField(max_length=100)
    locality = models.CharField(max_length=100)
    address = models.CharField(max_length=100)
    deposit_tk = models.CharField(max_length=100,blank=True)
    monthly_rent = models.CharField(max_length=100)
    prefer_type = models.CharField(max_length=100, default=False)
    response_set = models.CharField(max_length=100, default=False)
    status = models.CharField(max_length=100, default=False)

    # class Contact(models.Model):
    #   name = models.CharField(max_length=50)
    #  email = models.EmailField()
    # message = models.CharField(max_length = 2000)
    # def __str__(self):
    #   return self.name
