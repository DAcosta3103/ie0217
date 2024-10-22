/*Condiciones de carrera (race-condition)

Situación que ocurre cuando dos o más hilos o procesos acceden a una
memoria compartida al mismo tiempo y al menos uno de ellos está
realizando una operación de escritura, lo que ocasiona resultados
impredecibles y no deseados.

*/

// Supongamos que counter = 0
for (int i = 0; i < 1000; ++i) {
    ++counter; // Incremento no atómico
}

std::vector<int> myList;

// Hilo 1
myList.push_back(1);
// Hilo 2
myList.push_back(2);

//-----------------------------------------------------------------------------------------------------------

//Mecanismos de sincronización comunes

//Mutex (Mutual Exclusion): Un mecanismo que permite a los hilos tomar turnos para acceder a una sección crítica del código, asegurando que solo un hilo a
//la vez pueda ejecutarla.

std::mutex mtx;
void safeIncrement(int &counter) {
    std::lock_guard<std::mutex> lock(mtx);
    ++counter;
    // mtx se libera automáticamente cuando lock sale del ámbito
}

//Semáforos: Un contador que controla el acceso a uno o más recursos compartidos, permitiendo que un número limitado de hilos accedan a la sección crítica
//al mismo tiempo

std::counting_semaphore<1> sem(1);  // Semáforo binario (similar a un mutex)
void accessResource() {
    sem.acquire();  // Decrementa el contador y bloquea si el contador es cero
    // Sección crítica
    sem.release();  // Incrementa el contador y desbloquea a un hilo bloqueado
}

//----------------------------------Mecanismos de sincronización comunes-----------------------------------------------------------

//Variables de condición: Permiten que un hilo espere (bloquee) hasta que otro hilo señale (notifique) que una condición particular se ha cumplido

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void waitingThread() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });  // Espera hasta que ready sea true
    // Continuar ejecución
}

void notifyingThread() {
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    cv.notify_one();  // Notifica a uno de los hilos en espera
}


//Barreras de sincronización (Barriers): Permiten que un grupo de hilos espere hasta que todos los hilos en el grupo hayan alcanzado un punto de
//sincronización común antes de continuar.

std::barrier sync_point(5);  // Barrera para 5 hilos

void threadFunction() {
    // Realizar tareas antes de la barrera
    sync_point.arrive_and_wait();  // Esperar a que todos los hilos lleguen aquí
    // Continuar después de que todos los hilos hayan sincronizado
}

//---------------------------------Bloqueos y deadlocks--------------------------------------

/*

Bloqueo (Lock): Una situación en la que un hilo adquiere un recurso (como un mutex) y evita que otros hilos accedan a ese recurso hasta que sea liberado.
Propósito: Asegurar que sólo un hilo a la vez pueda ejecutar una sección crítica de código para evitar condiciones de carrera.

Deadlock: Una situación en la que dos o más hilos se bloquean mutuamente y ninguno puede continuar su ejecución porque cada uno está esperando que
el otro libere un recurso.
Características:
- Ocurre cuando hay dependencia circular entre hilos.
- Ninguno de los hilos involucrados puede proceder.
*/

std::mutex mtx1, mtx2;

void threadA() {
    std::lock_guard<std::mutex> lock1(mtx1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock2(mtx2);
}

void threadB() {
    std::lock_guard<std::mutex> lock2(mtx2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock1(mtx1);
}
