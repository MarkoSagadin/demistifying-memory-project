#include <zephyr/kernel.h>
#include <zephyr/sys/sys_heap.h>

extern struct k_heap heap;
extern struct k_mem_slab slab;

void print_usage(void)
{
	k_spinlock_key_t key;
	struct sys_memory_stats stats;
	struct k_mem_slab_info info;

	key = k_spin_lock(&heap->lock);
	sys_heap_runtime_stats_get(&heap->heap, &stats);
	k_spin_unlock(&heap->lock, key);

	key = k_spin_lock(&slab->lock);
	info = slab.info;
	k_spin_unlock(&slab->lock, key);

	printk("Heap stats\n"
		"\t%zu free, %zu allocated, %zu max allocated", 
		stats.free_bytes,
		stats.allocated_bytes, 
		stats.max_allocated_bytes);

	printk("Slab stats\n"
		"%u blocks, %zu block size, %u used, %u max used", 
		info.num_blocks,
		info.block_size, 
		info.num_used, 
		info.max_used);
}
