#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief Valida la cadena de caracteres a ingresar(solo letras).
 *
 * \param buffer, Array de caracteres a validar
 * \param maxCadena, Entero
 * \return entero indicando 1 si fue correcto el ingreso o 0 si no lo fue.
 *
 */

int validaCadena(char* buffer, int maxCadena);

/** \brief Nos indica si la cadena ingresada es numerica.
 *
 * \param numero, Array de caracteres a validar.
 * \return 1 si lo que se ingreso fueron numeros o 0 si no lo fue
 *
 */

int esNumeroYPositivo(char* numero);

/** \brief Nos captura la cadena a validar
 *
 * \param buffer, Array de caracteres a validar
 * \param textoError, Texto que se muestra si lo que se ingreso no es correcto
 * \param tamDeseado, Entero que representa el tamaño que se desea validar
 * \return Vacio.
 *
 */


void capturarCadena(char* buffer, char* textoError, int tamDeseado);

#endif // VALIDACIONES_H_INCLUDED
