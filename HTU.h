/*
 * Author: Fahad Mirza (fahadmirza80@yahoo.com)
 * Last edited: May 21st , 2016
 * 
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __HTU_H
#define __HTU_H


#ifdef __cplusplus
extern "C" {
#endif

void initHTU21D(void);
void getSensorData(float* Temperature, float* Humidity);

#ifdef __cplusplus
}
#endif


#endif//__HTU_H

