# FTP_Server
qt based FTP server using lib


## qmake build

    git clone https://github.com/anil-arise1600/FTP_Server.git
    cd FTP_Server
    mkdir qBuild & cd qBuild
    qmake ..
    make
    
## cmake build

    git clone https://github.com/anil-arise1600/FTP_Server.git
    cd FTP_Server
    mkdir cBuild & cd cBuild
    cmake ..
    make

## Run Server

copy certificate to app path

    cp ../QFtpServerLib/softcom.* ftpServerWindow/
    
start

    ftpServerWindow/ftpServerWindow

* Now start any ftp client to access files. i. e. FTP client [filezilla](https://filezilla-project.org/).

* Default credentail details
1. User ID : admin
2. Password : admin123
3. Port : 2323
