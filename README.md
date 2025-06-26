# Example of Linux traffic shaping

Example of traffic shaping under Linux. Two approaches are shown:

1) Use iptables to mark all packets for specific IP address
2) Use cgroups and eBPF to mark only packets belonging to certain cgroups (v2)


## Create files and folders

The 1) approach is hashed out in the script. The required iptables command is shown there.
The 2) approach requires to compile bpf-mark.c and load the module. It's expected that given process that we want to shape is already in appropriate cgroup.

Script is shaping traffic to backup server (172.31.1.14) from any process belonging to backup.slice. 
To test this we need to first create backup slice:

Systemd file ````/etc/systemd/system/backup.slice````:
````
[Unit]
Description=slice for backup users

[Slice]
CPUAccounting=true
````
Don't forget to do ````sytemctl daemon-reload````

Now you can test the upload to a backup server:
````
systemd-run -t --slice=backup.slice scp /root/bigblob 172.31.1.14:/tmp
````

