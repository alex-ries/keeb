from kb import KMKKeyboard
from kmk.keys import KC
from kmk.modules.layers import Layers
from kmk.modules.modtap import ModTap
from kmk.hid import HIDModes
from kmk.handlers.sequences import send_string
import supervisor
from kmk.extensions.peg_oled_Display import Oled,OledDisplayMode,OledReactionType,OledData
from kmk.extensions.peg_rgb_matrix import Rgb_matrix
from kmk.modules.split import Split, SplitSide, SplitType

keyboard = KMKKeyboard()
modtap = ModTap()
layers_ext = Layers()

keyboard.modules.append(layers_ext)
keyboard.modules.append(modtap)
# codeblock
"""
Enable TapDance
This codeblock enable TapDance to be used on the keyboard.
"""

from kmk.modules.tapdance import TapDance
tapdance = TapDance()
keyboard.modules.append(tapdance)
# codeblock
# codeblock
"""
Enable Debug
This codeblock enables debug mode
"""
keyboard.debug_enabled = True
# codeblock
# oled
oled_ext = Oled( OledData(image={0:OledReactionType.LAYER,1:["1.bmp","2.bmp","3.bmp","4.bmp","5.bmp","6.bmp","7.bmp","8.bmp"]}),toDisplay=OledDisplayMode.IMG,flip=False)
# oled
keyboard.extensions.append(oled_ext)
# ledmap
rgb_ext = Rgb_matrix(ledDisplay=[
[85,0,255],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[0,255,234],    [0,255,234],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[85,0,255],
[85,0,255],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[0,255,234],    [0,255,234],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[85,0,255],
[85,0,255],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[0,255,234],    [0,255,234],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[85,0,255],
[85,0,255],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[0,255,234],    [85,0,255],[85,0,255],    [0,255,234],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[85,0,255],
[85,0,255],[85,0,255],[85,0,255],[0,255,234],    [0,255,234],[85,0,255],[85,0,255],[85,0,255],
# Underglow
[85,0,255],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[85,0,255],    [85,0,255],[0,255,234],[0,255,234],[0,255,234],[0,255,234],[85,0,255]
],split=True,rightSide=False,disable_auto_write=True)
# ledmap
keyboard.extensions.append(rgb_ext)
# TODO Comment one of these on each side
#split_side = SplitSide.LEFT
#split_side = SplitSide.RIGHT
split = Split(data_pin=keyboard.rx, data_pin2=keyboard.tx, uart_flip=False)
keyboard.modules.append(split)
# encodercount
# 2
# encodercount
# keymap
# Layer 0 Base
keyboard.keymap = [ 
[
KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.ESC,KC.Q,KC.W,KC.F,KC.P,KC.B, KC.J,KC.L,KC.U,KC.Y,KC.QUOT,KC.NO,
KC.BSPC,KC.MT(KC.A,KC.LGUI,tap_time=200),KC.MT(KC.R,KC.LALT,tap_time=200),KC.MT(KC.S,KC.LCTRL,tap_time=200),KC.MT(KC.T, KC.LSFT, tap_time=200),KC.G,    KC.M,KC.MT(KC.N, KC.LSFT, tap_time=200),KC.MT(KC.E, KC.LCTRL, tap_time=200),KC.MT(KC.I, KC.LALT, tap_time=200),KC.MT(KC.O, KC.LGUI, tap_time=200),KC.NO,
KC.DEL,KC.Z,KC.MT(KC.X,KC.RALT,tap_time=200),KC.C,KC.D,KC.V,   KC.MUTE,KC.TD(KC.MPLY,KC.TO(1)),    KC.K,KC.H,KC.COMMA,KC.MT(KC.DOT,KC.RALT,tap_time=200),KC.SLASH,KC.NO,
KC.NO,KC.LT(3,KC.ESC,tap_time=200),KC.LT(4,KC.TAB,tap_time=200),KC.LT(2,KC.SPC,tap_time=200),   KC.LT(5,KC.ENT,tap_time=200),KC.LT(6,KC.BSPC,tap_time=200),KC.LT(7,KC.DEL,tap_time=200),KC.NO,
KC.AUDIO_VOL_UP,KC.AUDIO_VOL_DOWN,
KC.MEDIA_PREV_TRACK,KC.MEDIA_NEXT_TRACK],
# Layer 1 Gaming QWERTY
[
KC.ESC,KC.N1,KC.N2,KC.N3,KC.N4,KC.N5,    KC.N6,KC.N7,KC.N8,KC.N9,KC.N0,KC.NO,
KC.TAB,KC.Q,KC.W,KC.E,KC.R,KC.T,    KC.Y,KC.U,KC.I,KC.O,KC.P,KC.BSLASH,
KC.LSFT,KC.A,KC.S,KC.D,KC.F,KC.G,    KC.H,KC.J,KC.K,KC.L,KC.UP,KC.QUOT,
KC.LCTL,KC.Z,KC.X,KC.C,KC.V,KC.B,    KC.TRNS,KC.TD(KC.MPLY,KC.TO(0)),    KC.N,KC.M,KC.COMM,KC.LEFT,KC.DOWN,KC.RGHT,
KC.NO,KC.NO,KC.SPC,KC.LALT,    KC.F1,KC.F2,KC.F3,KC.F4,
KC.TRNS,KC.TRNS,
KC.TRNS,KC.TRNS],
# Layer 2 Nav
[
KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.RESET,KC.NO,KC.NO,KC.NO,KC.NO,    KC.LCTL(KC.Y),KC.LCTL(KC.Z),KC.LCTL(KC.X),KC.LCTL(KC.C),KC.LCTL(KC.V),KC.NO,
KC.NO,KC.LGUI,KC.LALT,KC.LCTRL,KC.LSHIFT,KC.NO,   KC.CAPSLOCK,KC.LEFT,KC.DOWN,KC.UP,KC.RIGHT,KC.NO,
KC.NO,KC.NO,KC.RALT,KC.NO,KC.NO,KC.NO,  KC.NO,KC.NO,    KC.INSERT,KC.HOME,KC.PGDOWN,KC.PGUP,KC.END,KC.NO,
KC.NO,KC.NO,KC.NO,KC.NO,    KC.ENTER,KC.BSPC,KC.DELETE,KC.NO,
KC.AUDIO_VOL_UP,KC.AUDIO_VOL_DOWN,
KC.MEDIA_PREV_TRACK,KC.MEDIA_NEXT_TRACK],
# Layer 3 Media
[
KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.RESET,KC.NO,KC.NO,KC.NO,KC.NO,    KC.RGB_TOG,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.LGUI,KC.LALT,KC.LCTRL,KC.LSHIFT,KC.NO,    KC.NO,KC.MEDIA_PREV_TRACK,KC.AUDIO_VOL_DOWN,KC.AUDIO_VOL_UP,KC.MEDIA_NEXT_TRACK,KC.NO,
KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.NO,KC.NO,KC.NO,    KC.MSTP,KC.MPLY,KC.MUTE,KC.NO,
KC.NO,KC.NO,
KC.NO,KC.NO],
# Layer 4 Symbol Right
[
KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.RESET,KC.NO,KC.NO,KC.NO,KC.NO,    KC.PLUS,KC.LBRC,KC.RBRC,KC.BSLS,KC.DQT,KC.NO,
KC.NO,KC.LGUI,KC.LALT,KC.LCTRL,KC.LSHIFT,KC.NO,    KC.MINS,KC.LPRN,KC.RPRN,KC.EXLM,KC.EQL,KC.NO,
KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,    KC.PERC,KC.LCBR,KC.RCBR,KC.PIPE,KC.UNDS,KC.NO,
KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.NO,
KC.NO,KC.NO],
# Layer 5 Num
[
KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.LBRC,KC.N7,KC.N8,KC.N9,KC.RBRC,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.SCLN,KC.N4,KC.N5,KC.N6,KC.EQL,    KC.NO,KC.LSHIFT,KC.LCTRL,KC.LALT,KC.LGUI,KC.NO,
KC.NO,KC.GRV,KC.N1,KC.N2,KC.N3,KC.BSLS,    KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.RALT,KC.NO,KC.NO,
KC.NO,KC.NO,KC.NO,KC.N0,    KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.NO,
KC.NO,KC.NO],
# Layer 6 Symbols Left 
[
KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.NO,KC.AMPR,KC.LABK,KC.RABK,KC.CIRC,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.NO,KC.TILD,KC.COLN,KC.SCLN,KC.ASTR,    KC.NO,KC.LSHIFT,KC.LCTRL,KC.LALT,KC.LGUI,KC.NO,
KC.NO,KC.NO,KC.AT,KC.DLR,KC.PIPE,KC.HASH,    KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.RALT,KC.NO,KC.NO,
KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.NO,
KC.NO,KC.NO],
# Layer 7 Function
[
KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.F12,KC.F7,KC.F8,KC.F9,KC.PSCR,    KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.F11,KC.F4,KC.F5,KC.F6,KC.SLCK,    KC.NO,KC.LSHIFT,KC.LCTRL,KC.LALT,KC.LGUI,KC.NO,
KC.NO,KC.F10,KC.F1,KC.F2,KC.F3,KC.BRK,    KC.NO,KC.NO,    KC.NO,KC.NO,KC.NO,KC.RALT,KC.NO,KC.NO,
KC.NO,KC.APP,KC.SPC,KC.TAB,    KC.NO,KC.NO,KC.NO,KC.NO,
KC.NO,KC.NO,
KC.NO,KC.NO]
]# keymap
if __name__ == '__main__': 
    keyboard.go(hid_type=HIDModes.USB)