#include "topK.h"

void topK(DataType *g_distances, DataType * g_dist, int *g_index){
#pragma HLS INTERFACE s_axilite port=g_distances bundle=control
#pragma HLS INTERFACE s_axilite port=g_dist bundle=control
#pragma HLS INTERFACE s_axilite port=g_index bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control
#pragma HLS INTERFACE m_axi depth=65536 port=g_distances bundle=gmem
#pragma HLS INTERFACE m_axi depth=16 port=g_dist bundle=gmem
#pragma HLS INTERFACE m_axi depth=16 port=g_index bundle=gmem0

	DataType l_dist[K];
#pragma HLS ARRAY_PARTITION variable=l_dist complete dim=1
	int l_index[K];

	loop_init:for(int i = 0;i<K;i++){
#pragma HLS PIPELINE
		l_dist[i] = g_distances[i];
		l_index[i] = i;
	}

	loop_pipe:for(int i = K;i<N;i++){
#pragma HLS PIPELINE
		DataType d = g_distances[i];
		DataType maxD = d;
		int maxI = -1;
		loop_unroll:for(int j=0;j<K;j++){
			if(l_dist[j] > maxD){
				maxD = l_dist[j];
				maxI = j;
			}
		}
		if(maxI != -1){
			l_dist[maxI] = d;
			l_index[maxI] = i;
		}
	}
	loop_assign:for(int i = 0;i<K;i++){
#pragma HLS PIPELINE
		g_dist[i] = l_dist[i];
		g_index[i] = l_index[i];
	}

}
