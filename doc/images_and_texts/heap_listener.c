#include <zephyr/sys/heap_listener.h>

static size_t total = 0;
extern struct k_heap some_heap;

static void alloc_cb(uintptr_t heap_id, void *mem, size_t bytes)
{
	total += bytes;
	LOG_INF("Alloc %d bytes, %u total", bytes, total);
}

static void free_cb(uintptr_t heap_id, void *mem, size_t bytes)
{
	total -= bytes;
	LOG_INF("Freed %u bytes", bytes);
}

HEAP_LISTENER_ALLOC_DEFINE(alloc_listener, 
			   HEAP_ID_FROM_POINTER(&some_heap),
			   alloc_cb);
HEAP_LISTENER_FREE_DEFINE(free_listener, 
			  HEAP_ID_FROM_POINTER(&some_heap),
			  free_cb);
