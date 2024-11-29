import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

cg.add_library(
    name="ESPAlexa",
    repository="https://github.com/creepystefan/ESPHOME-Alexa",
    version=None,
)
cg.add_library('WebServer', '')
cg.add_library('WiFiServer', '')

myespalexa_ns = cg.esphome_ns.namespace("myespalexa")
MYESPALEXA = myespalexa_ns.class_("MYESPALEXA", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(MYESPALEXA),
                       
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)


