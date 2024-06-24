import esphome.config_validation as cv

CONF_MY_REQUIRED_KEY = 'alexa'
CONF_MY_OPTIONAL_KEY = 'my_optional_key'

CONFIG_SCHEMA = cv.Schema({
  cv.Required(CONF_MY_REQUIRED_KEY): cv.string,
  cv.Optional(CONF_MY_OPTIONAL_KEY, default=10): cv.int_,
}).extend(cv.COMPONENT_SCHEMA)
