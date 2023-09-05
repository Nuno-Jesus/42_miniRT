/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:31:21 by marvin            #+#    #+#             */
/*   Updated: 2023/03/17 15:31:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_STR_H
# define NC_STR_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief Counts the number of characters in a string.
 * 
 * @param s The string to count.
 * @return size_t The number of characters in the string.
 */
size_t	nc_strlen(const char *s);

/**
 * @brief Counts the number of characters in a string until
 * a one of the characters in delim is found.
 * 
 * @param s The string to count.
 * @param delim The set of delimiters.
 * @return size_t The number of characters in the string.
 */
size_t	nc_strclen(char *str, char *delim);

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src
 * to dst, NUL-terminating the result.
 * 
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination string .
 * @return size_t The total length of the string they tried to create.
 */
size_t	nc_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated string src to the end of dst. It will append
 * at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
 * 
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination string.
 * @return size_t The total length of the string they tried to create.
 */
size_t	nc_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Attempts to locate the first occurrence of character c (converted to
 * a char) in the string pointed to by s. The terminating null character is
 * considered to be part of the string; therefore if c is '\0', the functions
 * locate the terminating '\0'.
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * @return char* A pointer to the located character, or NULL if the character
 * does not appear in the string.
 */
char	*nc_strchr(const char *s, int c);

/**
 * @brief Attempts to locate the last occurrence of character c (converted to a
 * char) in the string pointed to by s. The terminating null character is
 * considered to be part of the string; therefore if c is '\0', the functions
 * locate the terminating '\0'.
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * @return char* A pointer to the located character, or NULL if the character
 * does not appear in the string.
 */
char	*nc_strrchr(const char *s, int c);

/**
 * @brief Searches for the first occurrence of the substring needle in the
 * string haystack, where not more than len characters are searched.
 * 
 * @param haystack The string to be searched.
 * @param needle The substring to search for.
 * @param len The number of characters to search at most in the haystack.
 * @return char* A pointer to the beginning of the substring, or NULL if the
 * substring is not found.
 */
char	*nc_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Compares the first n characters of the null-terminated 
 * strings s1 and s2.
 * 
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @param n The number of characters to compare
 * @return int An integer greater than, equal to, or less than 0, according as
 * the string s1 is greater than, equal to, or less than the string s2.
 */
int		nc_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Compares the null-terminated strings s1 and s2.
 * 
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @return int An integer greater than, equal to, or less than 0, according as
 * the string s1 is greater than, equal to, or less than the string s2.
 */
int		nc_strcmp(char *s1, char *s2);

/**
 * @brief Duplicates the string given in parameter
 * 
 * @param s The string to duplicate
 * @return char* A pointer to the new string
 * @return NULL If the allocation fails
 */
char	*nc_strdup(const char *s);

/**
 * @brief Returns a substring from the string s. The substring 
 * begins at index 'start' and is of maximum size 'len'.
 * 
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string s.
 * @param len The maximum length of the substring.
 * @return char* The substring.
 * @return NULL If the allocation fails.
 */
char	*nc_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Creates a new string, which is the result of the concatenation
 *  of s1 and s2.
 * 
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return char* The new string.
 * @return NULL If the allocation fails.
 */
char	*nc_strjoin(char const *s1, char const *s2);

/**
 * @brief Creates a new string which is the result of trimming the original
 * string from the set of characters given in parameter. 
 * 
 * @param s1 The string to trim.
 * @param set The set of characters to trim.
 * @return char* The new string.
 * @return NULL If the allocation fails.
 */
char	*nc_strtrim(char const *s1, char const *set);

/**
 * @brief Splits the string s using the character c as a delimiter.
 * 
 * @param s The string to split.
 * @param c The delimiter character.
 * @return char** The array of new strings resulting from the split.
 * @return NULL If the allocation fails.
 */
char	**nc_split(char const *s, char c);

/**
 * @brief Creates a new string by applying the function f to each character
 * of the string s.
 * 
 * @param s The string to iterate.
 * @param f The function to apply to each character.
 * @return char* The new string.
 * @return NULL If the allocation fails.
 */
char	*nc_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function f to each character of the string passed as
 * argument. Each character is passed by address to f to be modified if
 * necessary.
 * 
 * @param s The string to iterate.
 * @param f The function to apply to each character.
 */
void	nc_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Given a string, replace the first ocurrence of old 
 * with new and return the new string.
 * 
 * @note It does not free the memory of either str, old or new.
 * @param str The string to be modified.
 * @param old The string to remove.
 * @param new The string to add.
 * @return char* A new pointer to the new string.
 * @return NULL If the allocation fails OR if old is not found in str.
 */
char	*nc_replace(char *str, char *old, char *new);

/**
 * @brief Given a string, replace all ocurrences of old 
 * with new and return the new string.
 * 
 * @note It does not free the memory of either str, old or new.
 * @param str The string to be modified.
 * @param old The string to remove.
 * @param new The string to add.
 * @return char* A new pointer to the new string.
 * @return NULL If the allocation fails OR if old is not found in str.
 */
char	*nc_replace_all(char *str, char *old, char *new);

#endif