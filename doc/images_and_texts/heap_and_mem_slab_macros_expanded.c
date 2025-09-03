/* zephyr/kernel/mempool.c, line 62 */
char kheap__system_heap[K_HEAP_MEM_POOL_SIZE];

struct k_heap _system_heap = {
	.heap = {
		.init_mem = kheap__system_heap,
		.init_bytes = K_HEAP_MEM_POOL_SIZE,
	},
};

/* zephyr/subsys/net/ip/tcp.c, line 76 */
size_t size = CONFIG_NET_MAX_CONTEXTS * sizeof(struct tcp);
static char _k_mem_slab_buf_tcp_conns_slab[size];

static struct k_mem_slab tcp_conns_slab = {
	.buffer = _k_mem_slab_buf_tcp_conns_slab,
	/* Other struct members... */
};
