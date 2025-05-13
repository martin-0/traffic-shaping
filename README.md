# Example of Linux traffic shaping

Example of traffic shaping under Linux. Two approaches are shown

1) Use iptables to mark all packets to given source
2) Use cgroups and eBPF to mark only packets belonging to certain cgroups (v2)


## Create files and folders

The 1) approach is hashed out in the script. The required iptables command is shown there.
The 2) approach requires to compile bpf-mark.c and load the module. It's expected that given process that we want to shape is already in appropriate cgroup.
In my test example I created SSH daemon listening on port 2222 in its own slice. Due to the way how PAM works I had to create special PAM files for this process so that spawn sessions don't end up in the different slice ( pam_systemd makes some "magic" there).

**TODO**: maybe upload it here ?
