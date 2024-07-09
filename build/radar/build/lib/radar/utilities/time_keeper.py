from radar.utilities.utils import timestamp_msg_to_seconds


class TimeKeeper:
    def __init__(self):
        self._last_time_seconds = None

    def calculate_time_difference_and_update_internal_timestamp(self, timestamp_msg):
        if self._last_time_seconds is None:
            self._last_time_seconds = timestamp_msg_to_seconds(timestamp_msg)
            return 0.0
        else:
            current_time_seconds = timestamp_msg_to_seconds(timestamp_msg)
            time_difference_seconds = current_time_seconds - self._last_time_seconds
            self._last_time_seconds = current_time_seconds
            return time_difference_seconds
