# Generated by Django 3.1.6 on 2021-06-06 05:19

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('calc', '0015_auto_20210605_2147'),
    ]

    operations = [
        migrations.AlterField(
            model_name='advertise',
            name='available',
            field=models.CharField(max_length=100),
        ),
        migrations.AlterField(
            model_name='advertise',
            name='deposit_tk',
            field=models.CharField(blank=True, max_length=100),
        ),
    ]
