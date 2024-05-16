project('balise receiver', 'c',
    version : '1.0',
    meson_version : '>= 1.3.0',
    default_options : [
        'buildtype=debugoptimized',
        'warning_level=2'
    ])

assert(meson.is_cross_build(), 'Avr projects can only be built in a cross build environment.')

avrdude_speed = meson.get_external_property('avrdude_speed')
avrdude_programmer = meson.get_external_property('avrdude_programmer')

srcs = [
    'adc.c',
    'fft.c',
    'io.c',
    'sin_table.c',
    'tim0.c',
    'uart.c'
]

includes = [
    '.'
]

# compile code as static library to use in unit test
main_lib = static_library('main_lib', srcs, include_directories : includes)
main_dep = declare_dependency(link_with : main_lib, include_directories : includes)

exe = executable('receiver.elf', 'main.c', include_directories : includes, dependencies : main_dep)

objcopy = find_program('avr-objcopy')
hex = custom_target('hex',
    input : exe,
    output : 'receiver.hex',
    command: [objcopy, '-O', 'ihex', '-R', '.eeprom', '@INPUT@', '@OUTPUT@']
)

avrdude = find_program('avrdude')
run_target('upload',
    command : [avrdude,
    '-v',
    '-p' + target_machine.cpu(), '-P' + get_option('port'),  '-c' + avrdude_programmer, '-b' + avrdude_speed,
    '-D', '-Uflash:w:'.format(hex.full_path())],
    depends : hex
)
