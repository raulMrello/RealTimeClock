/*
 * RealTimeClock.h
 *
 *  Created on: Feb 2018
 *      Author: raulMrello
 *
 *	RealTimeClock es un interfaz que representa los servicios que proporciona un chip RTC para leer y actualizar
 *	la hora actual.
 */
 
#ifndef __RealTimeClock__H
#define __RealTimeClock__H

#include "mbed.h"

   
class RealTimeClock {
  public:
    
    /** Constructor y Destructor por defecto */
    RealTimeClock(bool defdbg) : _ready(false), _defdbg(defdbg) {}

    virtual ~RealTimeClock(){}


	/** Chequea el estado de inicialización del chip RTC
     *  @return True: inicializado, False: error en la inicialización
     */
    virtual bool ready(){
    	return _ready;
    }
  
  
	/** Lee la hora actual con formato standard
     *  @param t Recibe la hora en formato 'struct tm'
     *  @return Código de error o 0.
     */
    virtual int getTime(tm* t) = 0;
    
    
	/** Actualiza la hora del RTC
     *  @param t Hora para actualizar el RTC
     *  @return Código de error o 0.
     */
    virtual int setTime(tm &t) = 0;

  protected:
    bool _ready;
    bool _defdbg;

};
     


#endif /*__RealTimeClock__H */

/**** END OF FILE ****/


