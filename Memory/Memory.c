#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <linux/ioctl.h>
#include <sys/io.h>
#include <sys/mman.h>
#include <unistd.h>

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short int u16;
typedef unsigned char u8;
typedef long long s64;
typedef int s32;
typedef short int s16;
typedef char s8;

typedef int int32;
typedef short int int16;

typedef u8 BOOL;
typedef u8 BYTE;
typedef u16 WORD;
typedef u32 DWORD;
#define PBYTE u8 *
#define PWORD u16 *
#define PDWORD u32 *

typedef void *HANDLE;

#define TRUE 	1
#define FALSE 	0

# define PAGE_MASK 0xfff
# define PAGE_SHIFT 12
# define PAGE_SIZE 0x1000

static int spi_fd=0;

BOOL InitMemMgr(void)
{
	spi_fd = open("/dev/mem", O_RDWR);
	if (spi_fd < 0)
	{
		printf("open /dev/mem err in %s\n", __func__);
		return FALSE;
	}
	return TRUE;
}



//PBYTE MapPhysToLin(PBYTE pbPhysAddr, DWORD dwPhysSize, HANDLE *pPhysicalMemoryHandle)
PBYTE MapPhysToLin(PBYTE pbPhysAddr, DWORD dwPhysSize)
{
	void *map_base;
	BOOL ret;
	u32 start, off;

	/*if (!pPhysicalMemoryHandle) 
	{
		printf("handle err in %s\n", __func__);	
		return NULL;
	}*/

	start = (u32)pbPhysAddr & ~(PAGE_MASK);	
	off = (u32)pbPhysAddr & PAGE_MASK;	
	
	//BOOL map_phy_mem(void **base, u32 phy_addr, u32 size, u32 prot, u32 flag)
	map_base = mmap(NULL, off + dwPhysSize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_32BIT, spi_fd, start); 
	if (map_base == MAP_FAILED) 
	{
		printf("err map in %s\n", __func__);
		return FALSE;
	}
	
	
	
	//ret = map_phy_mem(&map_base, start, off + dwPhysSize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_32BIT);
	printf("--[Phy: %p, Map: %p, Size: %x]\n", start, map_base, off + dwPhysSize);
	/*if (!ret) 
	{
		printf("map err in %s\n", __func__);
		return FALSE;
	}
	mn = (mm_node *)malloc(sizeof(mm_node));
	memset(mn, 0, sizeof(mn));
	mn->size = off + dwPhysSize;
	mn->raddr = (u64)start;
	mn->lin_addr = 0;
	printf("add %llX %llX 0x%x\n", mn->lin_addr, mn->raddr, mn->size);

	if (pPhysicalMemoryHandle)
		*pPhysicalMemoryHandle = mn;
    */
	return (PBYTE)((u32)map_base + off);	
}

//after use this func, set pbLinAddr = NULL, or it would be seg. fault if u map mem again
//	with the same pbLinAddr
BOOL UnmapPhysicalMemory(PBYTE pbPhysAddr, DWORD dwPhysSize)
{
	/*BOOL ret;
	u32 start;

	mm_node *mn = (mm_node *)PhysicalMemoryHandle;

	if (!mn) return FALSE;

	start = (u32)pbLinAddr & ~(PAGE_MASK);	
	ret = unmap_phy_mem((void *)start, mn->size);
	printf("unmap %.8x %llX %d\n", start, mn->raddr, mn->size);
	if (!ret) return FALSE;

	free(mn);
	return TRUE;*/
	
	u32 start, off;
    BOOL Status;

	start = (u32)pbPhysAddr & ~(PAGE_MASK);	
	off = (u32)pbPhysAddr & PAGE_MASK;	
	
	Status = munmap(start, off + dwPhysSize);
	
	if (Status) 
	{
		printf("err unmap %p %d in %s\n", start, off + dwPhysSize, __func__);
		return FALSE;	
	}

	return TRUE;
	
}

BOOL CleanMemMgr(void)
{
	/*
	int ret;

	if (spi_fd < 0) return FALSE;

	ret = ioctl(spi_fd, SPI_IOC_FREE_MEM_ALL);
	if (ret) debug("free all physical memory error\n");
	*/
	close(spi_fd);
	return TRUE;
}
