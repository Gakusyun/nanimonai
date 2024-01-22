wget https://aka.ms/download-jdk/microsoft-jdk-21.0.1-linux-x64.tar.gz
sudo tar -zxvf microsoft-jdk-21.0.1-linux-x64.tar.gz -C /usr/local/
echo "export JAVA_HOME=/usr/local/jdk-21.0.1+12" >>~/.profile
echo "export PATH=$JAVA_HOME/bin:$PATH" >>~/.profile
source ~/.profile
