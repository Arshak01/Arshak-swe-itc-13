from django.http import HttpResponse
from django.contrib.auth import authenticate, login, logout
from django.shortcuts import render,redirect

def index(request):
    return HttpResponse("Hello world")

def detail(request, question_id):
    return HttpResponse("You're looking at question %s." % question_id)

def results(request, question_id):
    response = "You're looking at the results of question %s."
    return HttpResponse(response % question_id)

def vote(request, question_id):
    return HttpResponse("You're voting on question %s." % question_id)


def login(request):
    username = request.POST['username']
    password = request.POST['password']
    user = authenticate(request, username=username, password=password)
    if user is not None:
        login(request, user)
        return render(request, "./users.html")
    else:
        return redirect('./base.html')

def logout_view(request):
    logout(request)
    return redirect('./templates/registration.html')
    # Redirect to a success page.

def view(request):
    return render(request, "./users.html")
