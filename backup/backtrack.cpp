bool finished;

backtrack(int a[], int k, int n){
  int c[MAX_CANDIDATES];
  int numCandidates;
  int i;

  if(isSolution(a, k, n)){
    processSolution(a,k,n);
  }
  else{
    k=k+1;
    constructCandidates(a, k, n, c, &numCandidates);
    for(i=0; i<numCandidates; i++)
    {
      a[k]=c[i];
      make_move(a,k,n);
      backtrack(a,k,n);
      umakeMove(a,k,n);
      if(finished) return;
    }
  }
}


