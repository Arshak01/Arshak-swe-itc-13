If you want to delete all *.temp files from you Desktop before turning off your computer you need to go /etc/rc0/, add there your script which contains this command:
$ find ~/Desktop -name "*.temp" -delete.
Then change file permissiond and make it executable :
chmod +x
And save that file with name K99_script.
