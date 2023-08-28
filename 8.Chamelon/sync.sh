#!/bin/bash
cat /etc/hosts | awk '{print $2}' | sort > ~/nodes

HOSTS=`cat /etc/hosts | grep -v ib | awk '{print $2}'`
IPS=`cat /etc/hosts | grep -v ib | awk '{print $1}'`

rm -f ~/.ssh/known_hosts
for host in $HOSTS
do
  ssh-keyscan -H $host >> ~/.ssh/known_hosts
done

for ip in $IPS
do
  ssh-keyscan -H $ip >> ~/.ssh/known_hosts
done

for host in $HOSTS
do
  echo "Copying to node $host ..."
  scp -q /etc/hosts $host:/tmp/hosts
  scp -q ~/nodes $host:~/nodes
  scp -q ~/.ssh/* $host:~/.ssh/
  scp -q ~/.bashrc $host:~/.bashrc
  scp -q ~/.bash_aliases $host:~/.bash_aliases
  ssh $host "sudo mv /tmp/hosts /etc/hosts"
done
