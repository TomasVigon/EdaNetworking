

#ifndef CLIENT_H
#define CLIENT_H

#define APR_DECLARE_STATIC
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include <assert.h>
#include <unistd.h>     //Para usar la funcion Sleep()

#include <apr_general.h>
#include <apr_network_io.h>
#include <apr_strings.h>


#define DEF_REMOTE_HOST	"127.0.0.1" 					  //IP al que nos queremos conectar
#define DEF_REMOTE_PORT	15667							  //Port al que nos queremos conectar
#define DEF_SOCK_TIMEOUT (APR_USEC_PER_SEC * 5) //TIMEOUT (ver más adelante).
#define BUFSIZE	516 									

using namespace std;


class client {
public:
    client();
    client(const client& orig);
    virtual ~client();
    /** Función auxiliar doConnect()
    * Intenta conectarse a al puerto DEF_REMOTE_PORT del server DEF_REMOTE_HOST.
    * Devuelve en su nombre apr_status_t: 
    *    -> En caso de resultar en una conexión satisfactoria vale APR_SUCCESS
    * En sock recibe un puntero a un apr_socket_t * el cual modifica con el apr_socket_t * que identifica a la conexión.
    * En mp recibe un apr_pool_t * inizializado que representa el memory pool necesario para el funcionamiento de las funciones de la librería APR.
    -> Este memory pool se debe haber creado previamente con apr_pool_create() y debe permanecer in scope hasta que se haya terminado de utilizar el sock recibido.**/
    void doClientConnect(); 
    apr_status_t getRV();
    void setCheck(bool status);
    /** Función auxiliar doClientTask()
    * Envia el string "Huston tenemos un problema" al sock recibido como primer parámetro. Asume que el sock ya fue inicializado y la comunicación está activa.
    * Devuelve en su nombre apr_status_t: 
    *    -> En caso de resultar en una transferencia exitosa devuelve APR_SUCCESS. Caso contrario != APR_SUCCESS. 
    *    -> Con la función apr_strerror() se puede traducir el error recibido en un string legible para el usuario.
    * En sock recibe un apr_socket_t * inicializado (por ejemplo con la función doConnect()) a donde enviar el string.
    * En mp recibe un apr_pool_t * iniailizado que representa el memory pool necesario para el funcionamiento de las funciones de la librería APR.
    -> Este memory pool se debe haber creado previamente con apr_pool_create() y debe permanecer in scope mientras dure esta función.
    **/
    void sendInfo(string &str);
    void receiveInfo(string &str);
    bool isEvent(string& packet);

private:
    apr_status_t rv;   //esta variable la usamos para leer los errores y verificar cuando las cosas andan o no.
    apr_pool_t *mp;   //esta variable la conocemos del tp anterior.
    apr_socket_t *s;   //esta variable nombra un socket. El concepto de socket es central a networking y lo pueden encontrar acá: https://en.wikipedia.org/wiki/Network_socket.
    bool check;
    apr_size_t len;
};

#endif /* CLIENT_H */
