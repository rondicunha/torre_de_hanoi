#include <iostream>
#include<algorithm>
#include<cstring>


using namespace std;

void mostrarMatrix(int M[7][3], int nivel)
{
    cout<<endl<<endl;


    for (int i=0; i<nivel; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << "  " << M[i][j]<<"  ";
        }
        cout<<endl;
    }

}

void jogada(int M[7][3], int nivel,int pont,string nome)
{
    int PinO, PinD, disco;
    do
    {
        cout << " Sua vez "<<nome<<" \n Sua pontuacao eh: " <<pont<<"\n Digite o pino de origem" << endl;
        cin>> PinO;
    }
    while (PinO<1||PinO>3);

    do
    {
        cout<< " Digite o pino de destino" << endl;
        cin >> PinD;
    }
    while (PinD<1||PinD>3);

    int index = 0;
    bool acheiDisco = false;


    for(int i = nivel-1; i >= 0; i--)
    {

        if(M[i][PinO-1] != 0)
        {
            acheiDisco = true;
            index = i;
        }
    }

    if(acheiDisco == true)
    {
        disco = M[index][PinO-1];

        int index2 = 0;
        bool temEspaco = false;


        for(int i = 0; i < nivel; i++)
        {

            if(M[i][PinD-1] == 0)
            {
                temEspaco = true;
                index2 = i;
            }
        }


        if(temEspaco == true &&( M[index2 + 1][PinD-1] > disco || index2 == nivel-1))  //
        {
            M[index][PinO-1] = 0;
            M[index2][PinD-1] = disco;
        }
        else
        {
            cout<<"\nJogada inválida 2 !!\n";
        }
    }
    else
    {
        cout<<"\nJogada inválida 1 !!\n";

    }
}

void jogar(int nivel,string nome)
{
    int M[7][3] = {{1,0,0},{2,0,0},{3,0,0},{4,0,0},{5,0,0},{6,0,0},{7,0,0}};
    bool continuar = true;

    int lin;
    float pont;
    if(nivel == 1)
    {
        lin = 3;
        pont = 7;
    }
    else if(nivel == 2)
    {
        lin = 5;
        pont = 31;
    }
    else
    {
        lin = 7;
        pont = 127;
    }

    while(continuar)
    {
        mostrarMatrix(M, lin);

        jogada(M,lin,pont,nome);

        continuar = false;
        pont--;

        for(int j = 0; j < nivel; j++)
        {
            if(M[j][2] != j+1)
            {
                continuar = true;
            }
        }
    }
    mostrarMatrix(M, lin);
    cout<<"Fim de Jogo\n Parabens "<<nome<<" voce eh um genio\n Pontuacao: "<< pont<<endl;

}



void instrucoes ()
{
    cout<< endl;
    cout<<"FINALIDADE DO JOGO:" << endl;


    cout<< ". O jogo consiste em passar todos os discos para o ultimo pino,"<< endl;
    cout<< "sendo obrigatorio passar um de cada vez. O disco maior nao pode sobrepor"<< endl;
    cout<< "o menor em momento algum do jogo." << endl;
    cout<< endl;

    cout<< "JOGANDO:" << endl;
    cout<< " Voce tera que inserir o pino de origem e o pino de destino, fazendo assim o movimento do disco" << endl;
    cout<< "de um pino para o outro." << endl;
    cout<<"Sua pontuacao vai diminuindo a cada movimento executado, a melhor pontuacao possivel eh 0! Boa sorte!;" << endl;

    int op, nivel;
    string nome;


    cout<< "Deseja jogar?" << endl;
    cout<<"     1.Sim"<< endl;
    cout<<"     2.Nao"<< endl;
    cin>> op;
    cout<< endl;

    if(op==1)
    {
        do
        {
            cout<<"Digite o nivel de Jogo:\n";
            cin >> nivel;
            cout<< "Digite seu nome: " << endl;
            cin>>nome;
        }
        while (nivel<1||nivel>3);
        cout<< endl;
        cout<<"Insira seu nome:" << endl;
        cin.ignore();
        getline(cin,nome);
        cout<< endl;

        jogar(nivel,nome);
    }
}
int main ()
{
    int op;


    do
    {
        cout << "============Menu=============" << endl;
        cout << "         1- Jogar"<< endl;
        cout << "         2- Instrucoes" << endl;
        cout << "         3- Sair" << endl;
        cout << "         4- Multiplayer" << endl;
        cout << "=============================" << endl;
        cout << "Escolha sua opcao" << endl;
        cout << "=============================" << endl;
        cin >> op;
    }
    while (op<1||op>4);
    if (op==1)
    {
        int nivel;
        string nome;

        do
        {
            cout<<"Digite o nivel de Jogo:\n";
            cin >> nivel;
            cout<< "Digite seu nome: " << endl;
            cin.ignore();

            getline(cin,nome);
        }
        while (nivel<1||nivel>3);

        jogar(nivel,nome);
    }
    if (op==2)
    {
        instrucoes ();
    }
    if(op==4)
    {

        int nivel;
        string nome1, nome2;

        do
        {
            cout<<"Digite o nivel de Jogo:\n";
            cin >> nivel;
            cout<< "Digite nome do jogador 1:"<< endl;
            cin.ignore();
            getline(cin,nome1);
            cout<< "Digite nome do jogador 2:" << endl;
            cin.ignore();
            getline(cin,nome2);

        }
        while (nivel<1||nivel>3);


        cout<<"Vez de"<< nome1;
        jogar(nivel,nome1);
        cout<<"Vez de" << nome2;
        jogar(nivel,nome2);
    }

    if (op==3)
    {
        exit(666);
    }

}

