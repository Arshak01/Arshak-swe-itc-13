from django.urls import path,include
from apps.users.views import dashboard, register, image_upload,login,logout
from django.conf import settings
from django.conf.urls.static import static

urlpatterns = [
    path('accounts/', include("django.contrib.auth.urls")),
    path('dashboard/', dashboard, name="dashboard"),
    path('register/', register, name="register"),
    path('accounts/logout/', logout ,name='logout'),
    path('image-upload/', image_upload, name='image_upload'),
    path(r'', dashboard, name="dashboard"),

]
if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL,
                          document_root=settings.MEDIA_ROOT)