NUM_CHIRPS = 32  # number of chirps per frame (currently causes problems when used with two Tx)
CHIRPSAMPLES = 128  # number of samples per chirp
VERTICAL_ANTENNA = True
NR_RX = 3 + VERTICAL_ANTENNA  # number of active Rx from Tx1 (uses maximum the first three)
VIRTUAL_ANTENNA = False  # if set to true, second Tx is used along with Rx4 to create a fourth, virtual antenna
BANDWIDTH = 4 * 1e9
POST_CHIRP_DELAY = 250 * 1e-6 if VIRTUAL_ANTENNA else 500 * 1e-6
HORIZONTAL_MAP = [2, 0, 1]

RADAR_OFFSET = [0.05, 0.0]

MAX_ANGLE_DEGREE = 45
N_BEAMS = 90

RADAR_FRAME_ID = 'radar'
