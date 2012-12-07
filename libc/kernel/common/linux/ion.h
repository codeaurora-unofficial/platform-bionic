/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _LINUX_ION_H
#define _LINUX_ION_H
#include <linux/ioctl.h>
#include <linux/types.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ion_handle;
enum ion_heap_type {
 ION_HEAP_TYPE_SYSTEM,
 ION_HEAP_TYPE_SYSTEM_CONTIG,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_HEAP_TYPE_CARVEOUT,
 ION_HEAP_TYPE_IOMMU,
 ION_HEAP_TYPE_CP,
 ION_HEAP_TYPE_CUSTOM,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_NUM_HEAPS,
};
#define ION_HEAP_SYSTEM_MASK (1 << ION_HEAP_TYPE_SYSTEM)
#define ION_HEAP_SYSTEM_CONTIG_MASK (1 << ION_HEAP_TYPE_SYSTEM_CONTIG)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_HEAP_CARVEOUT_MASK (1 << ION_HEAP_TYPE_CARVEOUT)
#define ION_HEAP_CP_MASK (1 << ION_HEAP_TYPE_CP)
#define ION_FLAG_CACHED 1  
enum ion_heap_ids {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 INVALID_HEAP_ID = -1,
 ION_BOGUS_HEAP_DO_NOT_USE = 0,
 ION_CP_MM_HEAP_ID = 8,
 ION_CP_MFC_HEAP_ID = 12,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_CP_WB_HEAP_ID = 16,
 ION_CAMERA_HEAP_ID = 20,
 ION_SF_HEAP_ID = 24,
 ION_IOMMU_HEAP_ID = 25,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_QSECOM_HEAP_ID = 27,
 ION_AUDIO_HEAP_ID = 28,
 ION_MM_FIRMWARE_HEAP_ID = 29,
 ION_SYSTEM_HEAP_ID = 30,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_HEAP_ID_RESERVED = 31
};
enum ion_fixed_position {
 NOT_FIXED,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 FIXED_LOW,
 FIXED_MIDDLE,
 FIXED_HIGH,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_SECURE (1 << ION_HEAP_ID_RESERVED)
#define ION_HEAP(bit) (1 << (bit))
#define ION_VMALLOC_HEAP_NAME "vmalloc"
#define ION_AUDIO_HEAP_NAME "audio"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_SF_HEAP_NAME "sf"
#define ION_MM_HEAP_NAME "mm"
#define ION_CAMERA_HEAP_NAME "camera_preview"
#define ION_IOMMU_HEAP_NAME "iommu"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_MFC_HEAP_NAME "mfc"
#define ION_WB_HEAP_NAME "wb"
#define ION_MM_FIRMWARE_HEAP_NAME "mm_fw"
#define ION_QSECOM_HEAP_NAME "qsecom"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_FMEM_HEAP_NAME "fmem"
#define CACHED 1
#define UNCACHED 0
#define ION_CACHE_SHIFT 0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_SET_CACHE(__cache) ((__cache) << ION_CACHE_SHIFT)
#define ION_IS_CACHED(__flags) ((__flags) & (1 << ION_CACHE_SHIFT))
#define ION_IOMMU_UNMAP_DELAYED 1
struct ion_allocation_data {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 size_t len;
 size_t align;
 unsigned int heap_mask;
 unsigned int flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct ion_handle *handle;
};
struct ion_fd_data {
 struct ion_handle *handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int fd;
};
struct ion_handle_data {
 struct ion_handle *handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ion_custom_data {
 unsigned int cmd;
 unsigned long arg;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ion_flush_data {
 struct ion_handle *handle;
 int fd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 void *vaddr;
 unsigned int offset;
 unsigned int length;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ion_flag_data {
 struct ion_handle *handle;
 unsigned long flags;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_IOC_MAGIC 'I'
#define ION_IOC_ALLOC _IOWR(ION_IOC_MAGIC, 0,   struct ion_allocation_data)
#define ION_IOC_FREE _IOWR(ION_IOC_MAGIC, 1, struct ion_handle_data)
#define ION_IOC_MAP _IOWR(ION_IOC_MAGIC, 2, struct ion_fd_data)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_IOC_SHARE _IOWR(ION_IOC_MAGIC, 4, struct ion_fd_data)
#define ION_IOC_IMPORT _IOWR(ION_IOC_MAGIC, 5, struct ion_fd_data)
#define ION_IOC_CUSTOM _IOWR(ION_IOC_MAGIC, 6, struct ion_custom_data)
#define ION_IOC_CLEAN_CACHES _IOWR(ION_IOC_MAGIC, 20,   struct ion_flush_data)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_IOC_INV_CACHES _IOWR(ION_IOC_MAGIC, 21,   struct ion_flush_data)
#define ION_IOC_CLEAN_INV_CACHES _IOWR(ION_IOC_MAGIC, 22,   struct ion_flush_data)
#define ION_IOC_GET_FLAGS _IOWR(ION_IOC_MAGIC, 23,   struct ion_flag_data)
#define ION_IOC_SYNC _IOWR(ION_IOC_MAGIC, 42,   struct ion_flag_data)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif

