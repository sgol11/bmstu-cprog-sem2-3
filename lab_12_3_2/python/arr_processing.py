import ctypes
import checks

arr_lib = ctypes.CDLL("../arr_lib.dll")

# void fill_arr_with_prime_numbers(int *array, int size)
_fill_with_prime = arr_lib.fill_arr_with_prime_numbers
_fill_with_prime.argtypes = (ctypes.POINTER(ctypes.c_int),
                             ctypes.c_int)
_fill_with_prime.restype = None


def fill_arr_with_prime_numbers(n):

    arr = (ctypes.c_int * n)()
    _fill_with_prime(arr, n)

    return list(arr)


# int arr_transfer(int *array_1, int *array_2, int size, int num)
_arr_transfer = arr_lib.arr_transfer
_arr_transfer.argtypes = (ctypes.POINTER(ctypes.c_int),
                          ctypes.POINTER(ctypes.c_int),
                          ctypes.c_int,
                          ctypes.c_int)
_arr_transfer.restype = ctypes.c_int


def arr_transfer(array, num, method):

    n = len(array)
    arr = (ctypes.c_int * n)(*array)

    if method == 0:
        n_res = ctypes.c_int(2 * n)
    elif method == 1:
        n_res = ctypes.c_int(0)
        n_res.value = _arr_transfer(arr, None, n, num)

    res_arr = (ctypes.c_int * n_res.value)()
    n_res.value = _arr_transfer(arr, res_arr, n, num)

    return list(res_arr), n_res.value


def fill_arr(input_field, output_field):

    err, n = checks.check_size(input_field)

    if not err:
        arr = fill_arr_with_prime_numbers(n)
        output_arr(arr, n, output_field)


def input_arr(input_field, output_field):

    err, arr = checks.check_array(input_field)

    if not err:
        n = len(arr)
        output_arr(arr, n, output_field)


def transfer_arr(input_field, num_field, output_field, method):

    err, num = checks.check_number(num_field)

    if not err:
        arr_str = input_field['text']
        if arr_str != 'Empty':
            arr = [int(x) for x in arr_str.split()]
            res_arr, n_res = arr_transfer(arr, num, method.get())
            output_arr(res_arr, n_res, output_field)


def output_arr(arr, n, field):

    str_arr = ''
    for i in range(n):
        str_arr += str(arr[i]) + ' '

    if n == 0:
        field.config(text='Empty')
    else:
        field.config(text=str_arr)
