#include <cstdlib>
#include<sys/time.h>
#include <iostream>
#include <ctime>
#include<chrono>
#include<vector>
#include<algorithm>
using namespace std;
using namespace std::chrono;


//--------------------------------------------------------

int randomfunc(int);

static int dupl_count=0,N=0;

void find_dupl(vector<int>&);
void remove_dupl(vector<int>&);
void fillrandom(vector<int>&);
void bubbleSort(vector<int>);
void insertionSort(vector<int>);
void mergeSort(vector<int>,int,int);
void merge(vector<int>,int,int,int);
void heapify(vector<int>,int,int);
void heapSort(vector<int>,int);

static int merge_swap=0;
static int heap_swap=0,bubble_swap=0,insertion_swap=0;
//----------------------------------------------------------------
int main(int argc,char **argv) 
{
	srand48(time(0));  
	vector<int> mdata,mdatacopy,tmp;  
	int i=0;  N=atoi(argv[1]);
	long starttime,endtime,tmp_time;
	timeval t;
	fillrandom(mdata);
	//-----------------Time of a duplicate remove function----------------
	find_dupl(mdata);
	if(dupl_count>0){
		gettimeofday(&t,NULL);
		starttime = t.tv_sec;
		remove_dupl(mdata);
		gettimeofday(&t,NULL);
		endtime = t.tv_sec;
		cout<<"\nremove duplicate function takes "<<endtime-starttime <<" microseconds"<<endl;
		cout<<endl<<"Duplicate values removed\n"<<endl;
	}
	mdatacopy=mdata;
	random_shuffle(mdata.begin(), mdata.end(),randomfunc); 
	//------------time of a bubble sort------------------------
	cout<<"1) Bubble Sort "<<endl;
	cout<<"Sorting ......";
	cout.flush();
	gettimeofday(&t,NULL);
	starttime = t.tv_sec;
	bubbleSort(mdata);
	gettimeofday(&t,NULL);
	endtime = t.tv_sec;
	tmp_time=endtime-starttime;
	cout<<"\ntime(worst case) :  "<<tmp_time <<" seconds"<<endl;
	cout.flush();
	tmp=mdatacopy;
	gettimeofday(&t,NULL);
	starttime = t.tv_sec;
	bubbleSort(tmp);
	gettimeofday(&t,NULL);
	endtime = t.tv_sec;
	cout<<"\ntime(best case) :  "<<endtime-starttime <<" second"<<endl;
	cout<<"\ntime(avg case) : "<<((tmp_time+endtime-starttime)/2)<<" second"<<endl;
	cout<<"\nswap(worst case) :  "<<bubble_swap<<endl;
	cout<<"Time Difference(sorted and unsorted array) " <<tmp_time-endtime+starttime<<" second"<<endl;

	//-----------time of an insertion sort------------------------
	cout<<"\n2) Insertion Sort "<<endl;
	cout<<"sorting ......";
	cout.flush();
	gettimeofday(&t,NULL);
	starttime = t.tv_sec;
	insertionSort(mdata);
	gettimeofday(&t,NULL);
	endtime = t.tv_sec;
	tmp_time=endtime-starttime;
	cout<<"\ntime(worst case)  : "<<tmp_time<<" seconds"<<endl;

	cout.flush();
	tmp=mdatacopy;
	gettimeofday(&t,NULL);
	starttime = t.tv_sec;
	insertionSort(tmp);
	gettimeofday(&t,NULL);
	endtime = t.tv_sec;
	cout<<"\ntime(best case)  : "<<endtime-starttime <<" second"<<endl;
	cout<<"\ntime(avg case) : "<<((tmp_time+endtime-starttime)/2)<<" second"<<endl<<endl;
	cout<<"swap(worst case) : "<<insertion_swap<<endl;
	cout<<"Time Difference (sorted and unsorted array)"<<tmp_time-endtime+starttime<<" second"<<endl;
	//-----------time of an merge sort------------------------
	cout<<"\n3) Merge Sort "<<endl;
	cout<<"sorting ......";
	cout.flush();
	gettimeofday(&t,NULL);
	starttime = t.tv_sec;
	mergeSort(mdata,0,N);
	gettimeofday(&t,NULL);
	endtime = t.tv_sec;
	tmp_time=endtime-starttime;
	cout<<"\nTime(worst case) : "<<tmp_time<<" second"<<endl;
	cout.flush();
	tmp=mdatacopy;
	gettimeofday(&t,NULL);
	starttime = t.tv_sec;
	insertionSort(tmp);
	gettimeofday(&t,NULL);
	endtime = t.tv_sec;
	cout<<"\ntime(best case) : "<<endtime-starttime<<" second"<<endl;
	cout<<"\ntime(avg case) : "<<((tmp_time+endtime-starttime)/2)<<" second"<<endl<<endl;
	cout<<"swap(worst case) : "<<merge_swap<<endl;
	cout<<"Time Difference(sorted and unsorted array) "<<tmp_time-endtime+starttime<<" second"<<endl;
	//-----------time of an heap sort------------------------
	cout<<"\n4) heap Sort "<<endl;
	cout<<"sorting......";
	cout.flush();
	gettimeofday(&t,NULL);
	starttime = t.tv_sec;
	heapSort(mdata,N);
	gettimeofday(&t,NULL);
	endtime = t.tv_sec;
	tmp_time=endtime-starttime;
	cout<<"\nTime(worst case) : "<<tmp_time<<" second"<<endl;
	cout.flush();
	tmp=mdatacopy;
	gettimeofday(&t,NULL);
	starttime = t.tv_sec;
	heapSort(tmp,N);
	gettimeofday(&t,NULL);
	endtime = t.tv_sec;
	cout<<"\ntime(best case)  : "<<endtime-starttime<<" seconds"<<endl;
	cout<<"\ntime(avg case) : "<<((tmp_time+endtime-starttime)/2)<<" second"<<endl<<endl;
	cout<<"swap(worst case) : "<<heap_swap<<endl;
	cout<<"Time Difference(sorted and unsorted array) "<<tmp_time-endtime+starttime<<" second"<<endl;
}
void find_dupl(vector<int> &v){
	int i;
	dupl_count=0;
	sort(v.begin(),v.end());
	for(i=0;i<v.size()-1;++i){
		if(v[i]==v[i+1]){
			dupl_count++;
			cout<<"duplicate value  "<<v[i]<<" found at location "<<i<<endl;
		} 
	}
	cout<<"\ntotal number of duplicate values found "<<dupl_count<<endl<<endl;

};

void remove_dupl(vector<int> &v){
	int i;
	for(i=0;i<v.size();++i){
		if(v[i]==v[i+1]){
			v[i+1]=lrand48();
		}
	}
};
void fillrandom(vector<int> &a){
	int i=0;
	srand48(time(0));  
	while(i<N){
		a.push_back(lrand48());
		i++;
	}
	cout<<"vector Count "<<a.size();
	cout<<endl<<endl;

}
void bubbleSort(vector<int> a) {


	for(int i=0;i<=a.size();i++)
		for(int j=0;j<a.size()-1;j++)
			if(a[j]>a[j+1]){
				int tmp = a[j] ;
				a[j] = a[j+1];
				a[j+1] = tmp;
				bubble_swap++;
			}
}
void insertionSort(vector<int> a)
{
	int i, key, j;
	for (i = 1; i < a.size(); i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
		insertion_swap++;
	}
}
void mergeSort(vector<int> a, int l, int r)
{

	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);

		merge(a, l, m, r);
	}

}
void merge(vector<int> a, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
			merge_swap++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}
int randomfunc(int j){
	return lrand48()%j;
}

void heapSort(vector<int> arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i=n-1; i>0; i--)
	{
		swap(arr[0], arr[i]);
		heap_swap++;
		heapify(arr, i, 0);
	}
}

void heapify(vector<int> arr, int n, int i)
{
	int largest = i; 
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heap_swap++;

		heapify(arr, n, largest);
	}
}
