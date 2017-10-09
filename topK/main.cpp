#include <iostream>
#include "topK.h"
using namespace std;

void ref(float *distances, float* dist, int *index){
	float lastMin = -1, d;
	for(int i=0;i<K;i++){
		float min = 100;
		int l_index = 0;
		for(int j=0;j<N;j++){
			d = distances[j];
			if(d < min && d > lastMin){
				min = d;
				l_index = j;
			}
		}
		dist[i] = min;
		index[i] = l_index;
		lastMin = min;
	}
}


int main(){
	float distances[N],dist[K], r_dist[K];
	int index[K], r_index[K];
	for(int i=0;i<N;i++){
		distances[i] = i*(N-i + 0.5)/97979797;
		cout<<"distances["<<i<<"]="<<distances[i]<<endl;
	}
	for(int i=0;i<K;i++){
		dist[i] = 0;
		index[i] = 0;
	}

	ref(distances, r_dist, r_index);
	topK(distances, dist, index);
	for(int i=0;i<K;i++){
		cout<<"r_dist["<<r_index[i]<<"]="<<r_dist[i]<<endl;
	}

	for(int i=0;i<K;i++){
		cout<<"dist["<<index[i]<<"]="<<dist[i]<<endl;
	}

}
