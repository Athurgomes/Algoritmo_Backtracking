#include <iostream>
#include <vector>

using namespace std;

int totalSolucoes=0;

void imprimirSolucao(const vector<vector<int>>& tabuleiro){
    int N=tabuleiro.size();
    totalSolucoes++; 
    cout<<"Solucao "<<totalSolucoes<<":"<<endl;
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (tabuleiro[i][j]==1)
                cout<<"R ";
            else
                cout<<". ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool Verificacao(const vector<vector<int>>&tabuleiro, int linha, int col) {
    int i, j;
    int N=tabuleiro.size();
    for(i=0; i<col; i++)
        if (tabuleiro[linha][i]==1)
            return false;
    for(i=linha, j=col; i>=0 && j>=0; i--, j--)
        if(tabuleiro[i][j]==1)
            return false;
    for(i=linha, j=col; j>=0 && i<N; i++, j--)
        if(tabuleiro[i][j]==1)
            return false;
    return true;
}

void resolverNRainhasRecursivo(vector<vector<int>>& tabuleiro, int col) {
    int N=tabuleiro.size();

    if(col==N){
        imprimirSolucao(tabuleiro);
        return;
    }
    for(int i=0; i<N; i++){
        if(Verificacao(tabuleiro, i, col)){
            tabuleiro[i][col]=1;
            resolverNRainhasRecursivo(tabuleiro, col+1);
            tabuleiro[i][col]=0;
        }
    }
}

void resolverNRainhas(int n){
    if(n<4){
        cout<<"N deve ser maior ou igual a 4."<<endl;
        return;
    }
    totalSolucoes=0;
    vector<vector<int>>tabuleiro(n, vector<int>(n, 0));
    resolverNRainhasRecursivo(tabuleiro, 0);
    if(totalSolucoes==0)
        cout<<"Nenhuma solucao encontrada"<<endl;
    else
        cout<<"Total de solucoes encontradas: "<<totalSolucoes<<endl;
}

int main() {
    int n;
    cout<<"Digite o valor de N (N>=4): ";
    cin>>n;
    resolverNRainhas(n);
    return 0;
}