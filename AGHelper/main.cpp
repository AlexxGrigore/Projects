#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class AGHelperMatrix {

private:
    int n = 0, m = 0, maxi = 0;
    string *header;
    string* leader;
    string **matr;

    void logo() {
        string logoul = " █████╗  ██████╗ ██╗  ██╗███████╗██╗     ██████╗ ███████╗██████╗ \n"
                        "██╔══██╗██╔════╝ ██║  ██║██╔════╝██║     ██╔══██╗██╔════╝██╔══██╗\n"
                        "███████║██║  ███╗███████║█████╗  ██║     ██████╔╝█████╗  ██████╔╝\n"
                        "██╔══██║██║   ██║██╔══██║██╔══╝  ██║     ██╔═══╝ ██╔══╝  ██╔══██╗\n"
                        "██║  ██║╚██████╔╝██║  ██║███████╗███████╗██║     ███████╗██║  ██║\n"
                        "╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝";
        cout << logoul << endl << endl << endl << endl;
    }

    void initializare() {

        header = new string[m];
        leader = new string[n];
        matr = new string *[m];
        for (int i = 0; i < m; i++) {
            matr[i] = new string[n];
        }
    }

    string capsulare(string text, int dim) {
        string rez = "|";
        for (int i = 0; i < (dim - text.size()) / 2; i++) {
            rez += " ";
        }
        rez += text;
        for (int i = 0; i < (dim - text.size() + 1) / 2; i++) {
            rez += " ";
        }
        return rez;
    }

    void afis_despartitor(int lim) {
        for (int i = 0; i < lim; i++)
            cout << "-";
        cout << endl;
    }

public:
    AGHelperMatrix(int n, int m, int **matr, bool withHeader) {
        this->n = n;
        this->m = m;
        initializare();
        for (int j = 0; j < m; j++)
            this->header[j] = to_string(j);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this->matr[i][j] = to_string(matr[i][j]);
                maxi = max(maxi, (int) this->matr[i][j].size());

            }
        }
        maxi += 2;
        logo();

        if (withHeader) {
            ///header
            for (int i = 0; i < maxi + 1; i++)
                cout << " ";
            afis_despartitor((maxi + 1) * m + 1);
            for (int i = 0; i < maxi + 1; i++)
                cout << " ";
            for (int i = 0; i < m; i++) {
                cout << capsulare(to_string(i), maxi);
            }
            cout << "|" << endl;
            afis_despartitor((maxi + 2) * m + 1);
            ///celule
            for (int i = 0; i < n; i++) {
                ///left
                cout << capsulare(to_string(i), maxi);

                for (int j = 0; j < m; j++) {
                    cout << capsulare(this->matr[i][j], maxi);
                }
                cout << "|" << endl;
                afis_despartitor((maxi + 2) * m + 1);
            }
        } else {
            afis_despartitor((maxi + 1) * m + 1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << capsulare(this->matr[i][j], maxi);
                }
                cout << "|" << endl;
                afis_despartitor((maxi + 1) * m + 1);
            }
        }


    }

    AGHelperMatrix(int n, int m, int **matr, int *header, int *leader) {
        this->n = n;
        this->m = m;
        initializare();
        ///header
        for (int j = 0; j < m; j++){
            this->header[j] = to_string(header[j]);
            maxi=max(maxi,(int)this->header[j].size());
        }
        ///leader
        for(int i=0; i<n; i++){
            this->leader[i]= to_string(leader[i]);
            maxi=max(maxi,(int)this->leader[i].size());
        }
        ///matr
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this->matr[i][j] = to_string(matr[i][j]);
                maxi = max(maxi, (int) this->matr[i][j].size());

            }
        }
        maxi += 2;
        logo();

        ///header
        for (int i = 0; i < maxi + 1; i++)
            cout << " ";
        afis_despartitor((maxi + 1) * m + 1);
        for (int i = 0; i < maxi + 1; i++)
            cout << " ";
        for (int i = 0; i < m; i++) {
            cout << capsulare(this->header[i], maxi);
        }
        cout << "|" << endl;
        afis_despartitor((maxi + 2) * m + 1);

        ///celule
        for (int i = 0; i < n; i++) {
            ///left
            cout << capsulare(this->leader[i], maxi);

            for (int j = 0; j < m; j++) {
                cout << capsulare(this->matr[i][j], maxi);
            }
            cout << "|" << endl;
            afis_despartitor((maxi + 2) * m + 1);
        }
    }

    AGHelperMatrix(int n, int m, int **matr, string *header, string *leader) {
        this->n = n;
        this->m = m;
        initializare();
        ///header
        for (int j = 0; j < m; j++){
            this->header[j] = header[j];
            maxi=max(maxi,(int)this->header[j].size());
        }
        ///leader
        for(int i=0; i<n; i++){
            this->leader[i]= leader[i];
            maxi=max(maxi,(int)this->leader[i].size());
        }
        ///matr
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this->matr[i][j] = to_string(matr[i][j]);
                maxi = max(maxi, (int) this->matr[i][j].size());

            }
        }
        maxi += 2;
        logo();

        ///header
        for (int i = 0; i < maxi + 1; i++)
            cout << " ";
        afis_despartitor((maxi + 1) * m + 1);
        for (int i = 0; i < maxi + 1; i++)
            cout << " ";
        for (int i = 0; i < m; i++) {
            cout << capsulare(this->header[i], maxi);
        }
        cout << "|" << endl;
        afis_despartitor((maxi + 3) * m);

        ///celule
        for (int i = 0; i < n; i++) {
            ///left
            cout << capsulare(this->leader[i], maxi);

            for (int j = 0; j < m; j++) {
                cout << capsulare(this->matr[i][j], maxi);
            }
            cout << "|" << endl;
            afis_despartitor((maxi + 3) * m);
        }
    }
};

int main() {
    int n, m;
    bool withheader = false;
    int *header;
    int*leader;
    string* Sheader;
    string* Sleader;
    int **matr;
    ifstream f("date.in");
    f >> n >> m;

    ///initializre
    header = new int[m];
    leader = new int[n];
    Sheader = new string[m];
    Sleader = new string[n];
    matr = new int *[m];
    for (int i = 0; i < m; i++) {
        matr[i] = new int[n];
    }
    ///citire
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f >> matr[i][j];
        }
    }

    f >> withheader;
    if (withheader){
        for (int j = 0; j < m; j++) {
            f >> Sheader[j];
        }
        for(int i=0; i<n; i++){
            f>> Sleader[i];
        }
    }
    
    AGHelperMatrix fereastra(n, m, matr, Sheader, Sleader);
    return 0;
}