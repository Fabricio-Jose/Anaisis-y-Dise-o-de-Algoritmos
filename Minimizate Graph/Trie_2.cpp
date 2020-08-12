#include<iostream>
#include <fstream>
using namespace std;
class Nodo{
    public:
        int h;
        Nodo *next_f[26];
		Nodo *next[26];
};

class Trie{
	private:
		Nodo* root;
		Nodo* fin[26];
	public:
		Trie(){
			root=new Nodo();
			root->h=0;
		}
    bool redirect(Nodo* temp,int before,Nodo* refe, string word, int i,int h_word,int pos, bool a){
        bool b=false;
        //Nodo*before=refe;
        int shar=0;
        
        for(int f=i;f<word.length();f++){
			shar = (int)word[f]-97;

            for(int j=0;j<26;j++){
                if(refe!=nullptr){
                if(refe->next_f[j]!=NULL){
                    if(f+1==word.length()){
                        if(j==shar){
                            return true;
                        }
                    }
                }
                
                if(refe==root->next[before]){
                   // cout<<"segundo root "<<endl;
                    b=redirect(temp,j,refe->next[j],word,i,h_word,pos,a);                    
                }else{
                    //if(refe->next_f[pos]!=nullptr){
                    if(refe->h==h_word){
                        if(before==pos){
                            cout<<"existe "<<word[f]<<endl;
                            temp->next[f]=refe;
                            //h_word=h_word-1;
                            b=redirect(temp,j,refe->next[j],word,i+1,h_word-1,shar,a);                            
                        }
                    }
                    //}
                }
               /* if(refe==root){
                    if(refe!=NULL){
                    if(refe->next[j]!=nullptr){
                        cout<<"primer root "<<j<<endl;
                        b=redirect(temp,j,refe->next[j],word,i,h_word,pos,a);
                    }}
                }else{
                    if(refe!=nullptr){
                    if(refe==root->next[before]){
                        if(refe!=NULL){
                        if(refe->next[j]!=NULL){
                            cout<<"segundo root "<<endl;
                            b=redirect(temp,j,refe->next[j],word,i,h_word,pos,a);
                        }
                        }
                    }else{
                        if(refe!=NULL){
                            if(refe->h==h_word){
                                if(before==pos){
                                    cout<<"existe "<<word[f]<<endl;
                                    temp->next[f]=refe;
                                    //h_word=h_word-1;
                                    b=redirect(temp,j,refe->next[j],word,i+1,h_word-1,pos+1,a);
                                }
                            }
                        }else{
                            return false;}
                    }}
                }*/
                }
            }
        }
        if(a==true){
            //cout<<"esto es a"<<endl;
            return true;}
        if(b==true){
            //cout<<"esto es b"<<endl;            
            return true;
        }else{
            //cout<<"esto es falso"<<endl;
            return false;
        }
    }

	void insert(string word){
		Nodo* temp = root;
		Nodo* refe = root;
		bool x=false;
        bool y=false;
		int h_word=word.length()-1;
        cout<<"tamano: "<<word.length()<<endl;
        int shar,shar_2=0;
		for(int i=0;i<word.length();i++){
			shar = (int)word[i]-97;
            cout<<"letra: "<<word[i]<<endl;
            //cout<<"numero: "<<shar<<endl;            
			if(temp->next[shar]==NULL){
                    if(i==(word.length()-1)){
                        if(fin[shar]==NULL){
                            fin[shar]=new Nodo();
                            temp->next_f[shar]=fin[shar];
                            temp->next_f[shar]->h=0;
                        }else{
                            temp->next_f[shar]=fin[shar];
                        }
                    }else{
                        if(temp==root){
                            temp->next[shar]=new Nodo();
                            temp->next[shar]->h=h_word;
                            h_word=h_word-1;
                            temp=temp->next[shar];
                            cout<<"altura "<<temp->h<<endl;
                        }else{//probleaaa
                            for(int j=0;j<26;j++){
                            y=redirect(temp,j,refe->next[j],word,i,h_word,shar,x);
                            if(y){
                                //cout<<"no se puedeeeeeeeeeeeeeee  "<<endl;
                                //redir(temp,refe->next[j],word,shar,h_word);
                                break;
                            }
                            }    //end for
                            if(y){
                                //cout<<"que pasooo  "<<endl;
                                break;
                            }else{
                            temp->next[shar]=new Nodo();
                            temp->next[shar]->h=h_word;
                            h_word=h_word-1;
                            temp=temp->next[shar];
                            cout<<"altura "<<temp->h<<endl;
                            }
                        }//fn problema
                    }
			}else{
                temp = temp->next[shar];
                temp->h=h_word;
                h_word=h_word-1;
                cout<<"altura "<<temp->h<<endl;
            }
		}
	}
	bool buscar(string word){
		Nodo* temp = root;
		int shar;
		for(int i = 0; i < word.length(); i++){
			shar = (int)word[i] - 97;
            if(i!=(word.length()-1)){
                if(temp->next[shar] == NULL){
                    return false;
                }else{
                    temp = temp->next[shar];
                }
            }else{
                if(temp->next_f[shar]==NULL){
                    return false;
                }else{
                    temp=temp->next_f[shar];
                }
            }
		}
		if(temp==fin[shar]){
			return true;
		}else{
			return false;
			}
	}
};

int main(){
	Trie trie;

	int nro;
	cout<<"Nro de paladras: ";
	cin>>nro;
	string word;

	for (int i = 0 ;i<nro; ++i){
		cin>>word;
		trie.insert(word);
	}
	
	for (int j=0;j<nro+1;j++){
	cout<<"Bucar palabra: ";
	cin>>word;
	cout<<trie.buscar(word)<<endl;
	}
	cout<<true;
	return 0;
}

