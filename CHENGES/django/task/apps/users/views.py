
from pprint import pprint
from django.http import HttpResponse
from django.contrib.auth import authenticate, login, logout
from django.shortcuts import redirect, render
from apps.users.forms import CustomUserCreationForm
from apps.users.forms import ImageForm
from apps.users.models import Image



def dashboard(request):
    return render(request, "users/dashboard.html")

def register(request):
    if request.method == "GET":
        return render(
            request, "users/register.html",
            {"form": CustomUserCreationForm}
        )

    elif request.method == "POST":
        form = CustomUserCreationForm(request.POST)
        if form.is_valid():
            user = form.save()
            login(request, user)
            return render(
                request, "users/dashboard.html",
                {"form": form}
            )
        else:
            return render(
                request, "users/register.html",
                {"form": form}
            )

def image_upload(request):
    if request.method == 'POST':
        form = ImageForm(request.POST, request.FILES)
        if form.is_valid():
            form.save()
            img_obj = form.instance
            return render(request, 'image_app.html', {'form': form, 'img_obj': img_obj})
    else:
        form = ImageForm()
    return render(request, 'image_app.html', {'form': form})

@register.filter(name='user')
def display(request):
    if request.method == 'GET':
        # Images = Image.objects.all()
        # pprint(Image.objects.title)
        Images = Image
        pprint(Image.objects.all())  #get(pk='')
        # pprint({'display': Images})
        return render(request, 'user_image_display.html', {'display': Images})