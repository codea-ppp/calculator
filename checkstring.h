#ifndef CHECKSTRING_H
#define CHECKSTRING_H

#define     IS_RADIOBUTTON                          (( 'r' == data[0] ))
#define     IS_RADIOBUTTON_BINARY_DEFAUT_RADIO      (( 'b' == data[12] ))
#define     IS_RADIOBUTTON_OCTAL_DEFAUT_RADIO       (( 'o' == data[12] ))
#define     IS_RADIOBUTTON_HEXADECIMAL_DEFAUT_RADIO (( 'h' == data[12] ))

#define     IS_NODE                                 (( '9' == data[19] && '4' == data[20] ))
#define     IS_BRACKET_RIGHT                        (( '9' == data[19] && '3' == data[20] ))
#define     IS_BRACKET_LEFT                         (( '9' == data[19] && '2' == data[20] ))
#define     IS_BACK                                 (( '9' == data[19] && '1' == data[20] ))
#define     IS_CE                                   (( '9' == data[19] && '0' == data[20] ))

#define     IS_ADD                                  (( '2' == data[19] && '0' == data[20] ))
#define     IS_LESS                                 (( '2' == data[19] && '1' == data[20] ))

#define     IS_SCIENCE                              (( 's' == data[11] ))
#define     IS_PROGRAM                              (( 'p' == data[11] ))

#define     IS_PROGRAM_NUMBER                       (( IS_PROGRAM && ('0' == data[19] || '1' == data[19]) ))
#define     IS_PROGRAM_NUMBER_DEFAUT_PROGRAM        (( '0' == data[19] || '1' == data[19] ))
#define     IS_PROGRAM_SPECIAL_BAN_DEFAUT_PROGRAM   (( '9' == data[19] && '5' == data[20] ))

#define     IS_PROGRAM_TWO_OPERANDS_OPERATOR_DEFAUT_PROGRAM         (( ('2' == data[19] && \
    ('0' == data[20] || '2' == data[20] || '3' == data[20] || '4' == data[20])) || \
    ('3' == data[19] && ('0' == data[20] || '1' == data[20] || '2' == data[20])) ))

#define     IS_PROGRAM_ONE_OPERANDS_OPERATOR_DEFAUT_PROGRAM         (( '3' == data[19] && \
    ('3' == data[20] || '4' == data[20] || '5' == data[20] || '6' == data[20] || '7' == data[20]) ))


#define     IS_SCIENCE_NUMBER_DEFAULT_SCIENCE       (( '0' == data[19] || '1' == data[19] ))

#define     IS_NOT_SCIENCE_SPECIAL_NUMBER_DEFAUT_SCIENCE            (( '1' != data[19] ))

#define     IS_SCIENCE_TWO_OPERANDS_OPERATOR_DEFAUT_SCIENCE         (( '2' == data[19] && \
    ('0' == data[20] || '2' == data[20] || '3' == data[20] || '4' == data[20])) || \
    ('3' == data[19] && '7' == data[20] ))

#define     IS_SCIENCE_ONE_OPERANDS_OPERATOR_DEFAUT_SCIENCE         (( '3' == data[19] && \
    ('0' == data[20] || '1' == data[20] || '2' == data[20] || '3' == data[20] || \
    '4' == data[20] || '5' == data[20] || '6' == data[20] || '8' == data[20]) ))


#define     IS_SCIENCE_COMPUTE_DEFAUT_SCIENCE       (( 'c' == containerScience->top()[0] ))
#define     IS_PROGRAM_COMPUTE_DEFAUT_PROGRAM       (( 'c' == containerProgram->top()[0] ))

#endif // CHECKSTRING_H
