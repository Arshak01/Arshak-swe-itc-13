from django.urls import path, re_path, include
from . import views
# from django.conf.urls import
from django.contrib.auth import views as auth_views

urlpatterns = [
    path('', views.index, name='index'),
    path('<int:question_id>/', views.detail, name='detail'),
    path('<int:question_id>/results/', views.results, name='results'),
    path('<int:question_id>/vote/', views.vote, name='vote'),
    path('accounts/login/', views.login, name='login'),
    path('accounts/logout/', views.logout_view, name='logout'),
    path('accounts/base/', views.login, name='base'),
    re_path(r"^view/", views.view, name="view"),
    re_path(r"^accounts/", include("django.contrib.auth.urls")),

]