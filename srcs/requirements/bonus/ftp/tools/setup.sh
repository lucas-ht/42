#!/bin/sh

if [ ! -f "/etc/vsftpd/vsftpd.conf.bak" ]; then

    echo "Initializing the FTP server...";

    mkdir -p /var/www/html;

    cp /etc/vsftpd/vsftpd.conf /etc/vsftpd/vsftpd.conf.bak;
    mv /tmp/vsftpd.conf /etc/vsftpd/vsftpd.conf;

    adduser $FTP_USER --disabled-password;

    echo "$FTP_USER:$FTP_PASSWORD" | /usr/sbin/chpasswd &> /dev/null;
    chown -R $FTP_USER:$FTP_USER /var/www/html;
    echo $FTP_USER | tee -a /etc/vsftpd.userlist &> /dev/null;

fi;

echo "Starting the FTP server...";
exec "$@";