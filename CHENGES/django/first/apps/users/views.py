import http
from pprint import pprint
from django.http import HttpResponse
from django.contrib.auth import authenticate, login, logout
from django.shortcuts import redirect, render
from apps.users.forms import CustomUserCreationForm
from apps.users.forms import ImageForm

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




# def login(request):
#     pprint("login : ")
#     pprint(request)
#     username = request.POST['username']
#     password = request.POST['password']
#     user = authenticate(request, username=username, password=password)
#     if user is not None:
#         login(request, user)
#         return render(request, "./users.html")
#     else:
#         return redirect('./templates/registration/login.html')

# def logout(request):
#     logout(request)
#     pprint("logout :    ")
#     return redirect('./templates/registration.html')


