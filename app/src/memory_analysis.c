#include <zephyr/shell/shell.h>
#include <zephyr/sys/sys_heap.h>

extern struct k_heap net_buf_mem_pool_rx_bufs;
extern struct k_heap net_buf_mem_pool_tx_bufs;
extern struct k_heap wifi_drv_ctrl_mem_pool;
extern struct k_heap wifi_drv_data_mem_pool;

static void print_heap_usage(const struct shell *sh, struct k_heap *heap, const char *name)
{
	struct sys_memory_stats stats;
	k_spinlock_key_t key;

	key = k_spin_lock(&heap->lock);
	sys_heap_runtime_stats_get(&heap->heap, &stats);
	k_spin_unlock(&heap->lock, key);

	shell_print(sh, "%s memory stats: \t%zu free, %zu allocated, %zu max allocated", name,
		    stats.free_bytes, stats.allocated_bytes, stats.max_allocated_bytes);
}

static int cmd_analyze(const struct shell *sh, size_t argc, char **argv)
{
	print_heap_usage(sh, &net_buf_mem_pool_tx_bufs, "Net TX buffers");
	print_heap_usage(sh, &net_buf_mem_pool_rx_bufs, "Net RX buffers");
	print_heap_usage(sh, &wifi_drv_ctrl_mem_pool, "nRF WiFi ctrl heap");
	print_heap_usage(sh, &wifi_drv_data_mem_pool, "nRF WiFi data heap");

	return 0;
}

SHELL_CMD_ARG_REGISTER(memory_analysis, NULL, "Memory analysis", cmd_analyze, 1, 0);
