int sparseTable[200005][25];
void preprocess(vector<int>&a){
    int n = a.size();
    FOR(i,0,n){
        sparseTable[i][0] = a[i];
    }
    FOR(i,1,25){
        for(int j = 0 ; j + (1<<i) -1 < n ; j++){
            sparseTable[j][i] = min(sparseTable[j][i-1],sparseTable[j+(1<<(i-1))][i-1]);
        }
    }
}
int query(int L,int R){
    int length = R-L+1;
    int tp = log2(length);
    return min(sparseTable[L][tp],sparseTable[R-(1<<tp)+1][tp]);
}
