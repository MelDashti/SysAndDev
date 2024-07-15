#include "iostream"
#include "thread"
#include "queue"
using namespace std;

bool running = true;
int command = -1;
condition_variable cv;
mutex mx;
vector<int> vt;

void writer(){

    while(running) {

        this_thread::sleep_for(chrono::milliseconds(5000));
        unique_lock<mutex> l_w(mx);
        vt.emplace_back(rand()%10+1);
        l_w.unlock();
    }

}

void worker(){

    while(running) {
        unique_lock<mutex> l_r(mx);
        cv.wait(l_r);

       if(!vt.empty()) {
            if(command == 1){
                cout << " ### Current elements: " << endl;
               for(auto& l : vt){
                    cout << "id: " << l << endl;
               }
            }else if(command== 2){
                cout << " ### Last inserted element: " << vt.back() << endl;
            }else if(command == 3){
                cout << " ### All elements have been removed" << endl;
                vt.clear();
            }
        }else{
            if(command ==-1) cout << " ### Shutting down all threads " << endl;
               else cout << " ### Vector empty " << endl;
        }
        l_r.unlock();
    }
}

void ui(){
   int temp;

    while(running) {

        cout << " === Type command :  shutdown=0, print all=1, print last=2, delete all=3 ===" << endl;
        std::cin >> temp;
        unique_lock<mutex> l_ui(mx);
            if(temp==0){

                running = false;
                command = -1;
                cv.notify_one();

            }else if(temp >=1 || temp <= 3){

                    command = temp;
                    cv.notify_one();

            }

        l_ui.unlock();
    }
}

int main(){
     cout << "PROGRAM START " << endl;

     thread t_wr(writer);
     thread t_u(ui);
     thread t_w(worker);

     t_wr.join();
     t_u.join();
     t_w.join();

     cout << "PROGRAM END " << endl;
}
