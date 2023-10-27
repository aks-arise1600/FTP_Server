# FTP_Server
qt based FTP server using lib


## qmake build

    git clone https://github.com/anil-arise1600/FTP_Server.git
    cd FTP_Server
    mkdir qBuild & cd qBuild
    qmake ..
    make

## Run Server

copy certificate to app path

    cp ../QFtpServerLib/softcom.* ftpServerWindow/
    
start

    ftpServerWindow/ftpServerWindow

Now start any ftp client to access files
For example filezilla.
Default credentail details
User ID : admin
Password : admin123
Port : 2323
