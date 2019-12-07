#include project_headers.h
#include <vector>
#include <cstdlib>
#include <ctime>

/*****************************************************************************
* Lets put a main function here. We can put each of our tests into separate
* text files, read them in, and then send them out to a class that will
* interpret the information. That class that interprets the information will
* contain the #include for project headers. We can also just leave all the 
* functions in here, and not have to worry about a different class. it doesn't
* matter to me either way.
*****************************************************************************/
using namespace std;
int main()
{
    int test1;
    return 0;
}

int TLB_lookup(unsigned int TLB[][5], int size, unsigned int vpn)
{
    int i = 0;
    while((TLB[i][3] != vpn && i < size)
    {
        i++;
    }
    return (i < size && TLB[i][0] != 0) ? i : -1;
}

int get_available_TLB_entry (unsigned int TLB[][5], int size)
{
    int i = 0;
    while(TLB[i][0] != 0 && i < size)
    {
        i++;
    }

    return (i < size) ? i : -1; 
}

unsigned int select_TLB_shootdown_candidate(unsigned int TLB[][5], int size)
{
    int shootdownCandidate;
    int i = 0;
    vector<int> unreferencedIndices;  //8 = size of TLB    

    srand(time(NULL))
    while(i < size)
    {
        if(TLB[i][2] == 0)
        {
            unreferencedIndices.push_back(i);
        }
        i++;
    }
    
    if(unreferencedIndices.end() == 0)
    {
        shootdownCandidate = rand() % size;
    }
    else
    {
        i = rand() % unreferencedIndices.end();
        shootdownCandidate = unreferencedIndices[i];
    }

    return shootdownCandidate;
}

void TLB_shootdown(unsigned int TLB[][5], int tlb_size, unsigned int PageTable[][4], int page_table_size, int index)
{
    pageTableIndex = TLB[index][tlb_size - 2];
    if(TLB[index][0] == 1)
    {
        TLB[index][0] == 0;
        pageTable[pageTableIndex][1] = TLB[index][1];   //1 is the location of D for both tables, so we can say column 1.
        pageTable[pageTableIndex][2] = TLB[index][2];   //2 is the location of R for both tables, so we can say column 2.
    }
}

int cache_translation_in_TLB(unsigned int TLB[][5], int tlb_size, unsigned int PageTable[][4], int page_table_size, unsigned int vpn)
{
    int index = get_available_TLB_entry(TLB[][5], tlb_size);
    int retVal = 0;
    
    if(index == -1)
    {
        int shootdownIndex = select_TLB_shootdown_candidate(TLB[][5], tlb_size)
        TLB_shootdown(TLB[][5], tlb_size, pageTable[][4],page_table_size, shootdownIndex)
        
        retVal = 1;
        
        index = shootDownIndex;
    }
    TLB[index][1] = pageTable[vpn][1];
    TLB[index][2] = pageTable[vpn][2];
    TLB[index][3] = vpn;
    TLB[index][4] = pageTable[vpn][3];

    return retVal;
}

int get_available_frame(unsigned int FrameTable[], int size)
{
    int i = 0;
    while(FrameTable[i] != 0 && i < size)
    {
        i++;
    }

    return (i < size) ? i : -1; 
}

int search_PageTable_by_VDR(unsigned int PageTable[][4], int size, int V, int D, int R)
{
    vector<int> validPages;
    int i = 0;
    int index;
    int retVal;

    srand(time(NULL))
    for(i = 0; i < size; i++)
    {
        if(PageTable[i][0] == V && PageTable[i][1] == D && PageTable[i][2] == R)
        {
            validPages.push_back(PageTable[i]);
        }
    }

    if(validPages.end() == 0)
    {
        retVal = -1;
    }
    else
    {
        index = rand() % validPages;
        retVal = validPages[index];
    }
    return retVal;
}

unsigned int select_page_eviction_candidate(unsigned int PageTable[][4], int size)
{
    int index = search_PageTable_by_VDR(PageTable[][4], 1, 0, 0);
    if(index == -1)
    {
        index = search_PageTable_by_VDR(PageTable[][4], 1, 1, 0);
    }
    if(index == -1)
    {
        index = search_PageTable_by_VDR(PageTable[][4], 1, 0, 1);
    }
    if(index == -1)
    {
        index = search_PageTable_by_VDR(PageTable[][4], 1, 1, 1);
    }

    return index;
}

int page_evict(unsigned int PageTable[][4], int page_table_size, unsigned int TLB[][5], int tlb_size, int FrameTable[], int frame_table_size, int vpn)
{
    int retVal = 0;
    int i = 0;
    int frame;
    while(i < tlb_size)
    {
        if(TLB[i][3] == vpn)
        {
            retVal += 1;
            TLB_shootdown(TLB[][5], tlb_size, PageTable[][4], page_table_size, i);
        }
        i++;
    }
    i = 0;
    while(i < page_table_size)
}

int cache_page_in_RAM(unsigned int PageTable[][4], int page_table_size, unsigned int TLB[][4], int tlb_size, unsigned int FrameTable[], int frame_table_size, unsigned int vpn, int read_write)
{
    int h = 0;
	int old = 0;
	if (get_available_frame(FrameTable[],frame_table_size)<0)
	{
		int h = page_evict(PageTable[][4],page_table_size,TLB[][5],tlb_size,FrameTable[],frame_table_size,vpn);
	}
	int old = cache_translation_in_TLB(TLB[][5], tlb_size, PageTable[][4], page_table_size, vpn);
	
	return (h+old);
}

void reset_reference_bits(unsigned int TLB[][5], int tlb_size, unsigned int PageTable[][4], int page_table_size)
{
    int i;
    for(i = 0; i < tlb_size; i++)
    {
        TLB[i][2] = 0;
    }

    i = 0;

    for(i = 0; i < page_table_size; i++)
    {
        PageTable[i][2] = 0; 
    }
}

void updateHits(int hit)
{
	int tbh = 0;
	int tbm = 0;
	int tbs = 0; 
	int pth = 0;
	int ptf = 0;
	int pge = 0;
	int hdw = 0;

	if (hit == 20)
	{
		tbh++;
	}
	if (hit == 19)
	{
		pth++;
	}
	if (hit == 18)
	{
		ptf++;
	}
	if (hit != 0)
	{
		if (hit == 111)
		{
			tbs++;
			hdw++;
			pge++;
		}
	}
	if (hit == 21)
	{
		cout << "TLB hits:" << tbh;
		cout << "TLB misses:" << tbm;
		cout << "TLB hit rate:" << tbh/tbm;
		cout << "TLB Shootdowns:" << tbs;
		cout << "TLB writes:" << tbm;
		cout << "Pg Table accesses:" << tbm;
		cout << "Pg Table hits:" << pth;
		cout << "Pg faults:" << ptf;
		cout << "Pg Table hit rates:" << pth/ptf;
		cout << "Pg Table eviction:" << pge;
		cout << "Pg Table writes:" << ptf;
		cout << "Hard disk reads:" << ptf;
		cout << "Hard disk writes:" << hdw;
	}
}

void memory_access (unsigned int TLB[][5], int tlb_size, unsigned int PageTable[][4], int page_table_size, unsigned int FrameTable[], int frame_table_size, unsigned int address, int read_write)
{
    int vpn = address / 1024;
	int offset = address % 1024;

	if (TLB_lookup(TLB[][5],tlb_size,vpn) < 0)
	{
		int hold = 0;
		if (search_PageTable_by_VDR(PageTable[][4],page_table_size,1,0,0) < 0 || search_PageTable_by_VDR(PageTable[][4], page_table_size, 1, 1, 0) < 0)
		{
			updateHits(18);
			hold = cache_page_in_RAM(PageTable[][4], page_table_size, TLB[][4], tlb_size, FrameTable[], frame_table_size, vpn, read_write);
			updateHits(hold);
		}
		else 
		{
			updateHits(19);
			int h = 0;
			int old = 0;
			if (get_available_frame(FrameTable[], frame_table_size) < 0)
			{
				 h = page_evict(PageTable[][4], page_table_size, TLB[][5], tlb_size, FrameTable[], frame_table_size, vpn);
			}
			 old = cache_translation_in_TLB(TLB[][5], tlb_size, PageTable[][4], page_table_size, vpn);
			hold = h + old;
			updateHits(hold);
		}
	}
	updateHits(20);
}