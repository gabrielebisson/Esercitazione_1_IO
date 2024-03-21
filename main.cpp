#include <iostream>
#include <fstream>
#include <iomanip>

double trasformazione(double v) //mappa [1,5] in [-1,2]
{
    return (3./4.)*v-(7./4.);
}

int main()
{
    std::string file_input="data.csv";
    std::string file_output = "result.csv";
    std::ifstream ifstr(file_input); // apre il file di input
    std::ofstream ofs(file_output); // crea il file di output
    if ( ifstr.is_open() && ofs.is_open()) { // se i 2 file sono aperti
        ofs << "# N mean\n";
        ofs<< std::setprecision(16); // imposta la precisione a 16 cifre dopo la virgola
        ofs.setf(std::ios_base::scientific); // imposta il formato in notazione scientifica, namespace iomanip
        double somma=0;
        int i=0;
        while( !ifstr.eof() ) { //diventa falso quando la lettura del file arriva alla fine
            i +=1;
            double numero;
            ifstr >> numero;
            double risultato=trasformazione(numero);
            somma += risultato;
            ofs <<i<<" "<< somma/i<<"\n";
        }
    }
    else
    {
        std::cerr<<"C'e' un errore nella lettura di '"<<file_input<<"' o nella creazione di '"<< file_output<<"' \n";
        return 1;
    }
    ofs.close(); //chiude i file
    ifstr.close();
    return 0;
}
