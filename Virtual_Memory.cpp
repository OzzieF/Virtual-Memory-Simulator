#include project_headers.h;
/*****************************************************************************
* Lets put a main function here. We can put each of our tests into separate
* text files, read them in, and then send them out to a class that will
* interpret the information. That class that interprets the information will
* contain the #include for project headers. We can also just leave all the 
* functions in here, and not have to worry about a different class. it doesn't
* matter to me either way.
*****************************************************************************/

int main()
{
    int test1
    return 0;
}

int TLB_lookup(unsigned int TLB[][5], int size, unsigned int vpn)
{

}

int get_available_TLB_entry (unsigned int TLB[][5], int size)
{

}

unsigned int select_TLB_shootdown_candidate(unsigned int TLB[][5], int size)
{

}

void TLB_shootdown(unsigned int TLB[][5], int tlb_size, unsigned int PageTable[][4], int page_table_size, int index)
{

}

int cache_translation_in_TLB(unsigned int TLB[][5], int tlb_size, unsigned int PageTable[][4], int page_table_size, unsigned int vpn)
{

}

int get_available_frame (unsigned int FrameTable[], int size)
{

}

int search_PageTable_by_VDR(unsigned int PageTable[][4], int size, int V, int D, int R)
{

}

unsigned int select_page_eviction_candidate(unsigned int PageTable[][4], int size)
{

}

int page_evict(unsigned int PageTable[][4], int page_table_size, unsigned int TLB[][5], int tlb_size, int FrameTable[], int frame_table_size, int vpn)
{

}

int cache_page_in_RAM(unsigned int PageTable[][4], int page_table_size, unsigned int TLB[][4], int tlb_size, unsigned int FrameTable[], int frame_table_size, unsigned int vpn, int read_write)
{

}

void reset_reference_bits(unsigned int TLB[][5], int tlb_size, unsigned int PageTable[][4], int page_table_size)
{

}

void memory_access (unsigned int TLB[][5], int tlb_size, unsigned int PageTable[][4], int page_table_size, unsigned int FrameTable[], int frame_table_size, unsigned int address, int read_write)
{
    
}