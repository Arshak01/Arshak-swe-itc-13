from django.contrib.auth.forms import UserCreationForm
from django import forms
from apps.users.models import Image
from django.contrib.auth.models import  User


class CustomUserCreationForm(UserCreationForm):
    class Meta(UserCreationForm.Meta):
        fields = UserCreationForm.Meta.fields + ("email",)

class ImageForm(forms.ModelForm):
    class Meta:
        model = Image
        fields = ('user', 'title', 'image')





