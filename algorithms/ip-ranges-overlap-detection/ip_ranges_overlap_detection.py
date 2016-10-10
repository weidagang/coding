import sys
import ipaddress
import functools

def is_overlapped(ip_ranges):
  '''Returns True if the IP ranges overlap.'''
  if has_duplicates(ip_ranges):
    return True

  range_set = frozenset(ip_ranges)
  for ip_range in ip_ranges:
    for super_range in super_ranges_of(ip_range):
      if super_range in range_set:
        return True
  return False

def has_duplicates(items):
  '''Returns True if there are duplicate items.'''
  uniques = set()
  for item in items:
    if item in uniques:
      return True
    uniques.add(item)
  return False

def super_ranges_of(ip_range_str):
  '''Yields the super ranges of an IP range.'''
  (ip_str, prefix_length_str) = ip_range_str.split('/')
  ip_int = ip_str_to_int(ip_str)
  prefix_length = int(prefix_length_str)
  while prefix_length > 0:
    prefix_length = prefix_length - 1
    ip_int = ip_int & mask_of(prefix_length)
    yield '%d.%d.%d.%d/%d' % (
      (ip_int >> 24) & 0xFF,
      (ip_int >> 16) & 0xFF,
      (ip_int >> 8) & 0xFF,
      ip_int & 0xFF,
      prefix_length)

def ip_range_str_to_int(ip_range_str):
  '''Parses IP range string to integer.

     e.g., "10.128.0.0/16" -> 0x0a800000.
  '''
  [part1, part2] = ip_range_str.split('/')
  ip_int = ip_str_to_int(part1)
  prefix_length = int(part2)
  return ip_int & mask_of(prefix_length)

def ip_str_to_int(ip_str):
  '''Converts an IP string to its integer representation.'''
  return functools.reduce(lambda sum, x: (sum << 8) + int(x), ip_str.split("."), 0)

def mask_of(prefix_length):
  '''Generates the bitmask of a prefix length.
  
     e.g., mask_of(8) -> 0xF0000000
  '''
  return (2 ** 32) - (2 ** (32 - prefix_length))

# Unit tests
if __name__ == '__main__':
  ip_ranges = []
  assert not is_overlapped(ip_ranges)

  ip_ranges = ['0.0.0.0/0']
  assert not is_overlapped(ip_ranges)

  ip_ranges = ['10.128.0.0/9', '10.128.0.0/9']
  assert is_overlapped(ip_ranges)

  ip_ranges = ['10.128.0.0/9', '10.128.0.0/10']
  assert is_overlapped(ip_ranges)

  ip_ranges = ['10.128.0.0/16', '10.129.0.0/16']
  assert not is_overlapped(ip_ranges)

  ip_ranges = ['10.128.0.0/9', '10.129.0.0/16']
  assert is_overlapped(ip_ranges)

  ip_ranges = ['10.128.0.1/32', '10.128.0.0/31']
  assert is_overlapped(ip_ranges)

  ip_ranges = ['10.128.0.1/32', '10.128.0.1/32']
  assert is_overlapped(ip_ranges)

  ip_ranges = ['10.128.0.1/32', '9.128.0.1/32']
  assert not is_overlapped(ip_ranges)
