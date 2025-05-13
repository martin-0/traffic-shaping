#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

SEC("cgroup/skb")

int mark_packets(struct __sk_buff *skb) {
    // Set a mark value; adjust as needed for your tc filter
    skb->mark = 0x14;
    return 1; // Allow the packet
}

char LICENSE[] SEC("license") = "GPL";

