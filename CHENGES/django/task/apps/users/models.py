from django.db import models
from django.contrib.auth.models import  User
from django.db.models import ForeignKey


class Image(models.Model):
    user = models.ForeignKey(
        User,
        null=True,
        on_delete=models.SET_NULL
    )
    title = models.CharField(max_length=200)
    image = models.ImageField(upload_to='images/%Y/%m/%d/', blank=True)
    image_data = models.BinaryField(null=True)

    def __str__(self):
        return self.title

