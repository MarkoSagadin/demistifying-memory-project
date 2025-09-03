/* zephyr/kernel/mempool.c, line 62 */
K_HEAP_DEFINE(_system_heap, K_HEAP_MEM_POOL_SIZE);

/* zephyr/subsys/net/ip/tcp.c, line 76 */
K_MEM_SLAB_DEFINE_STATIC(tcp_conns_slab, sizeof(struct tcp),
				CONFIG_NET_MAX_CONTEXTS, 4);

