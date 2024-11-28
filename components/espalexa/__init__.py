import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

espalexa_ns = cg.esphome_ns.namespace("espalexa")
ESPALEXA = espalexa_ns.class_("ESPALEXA", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(ESPALEXA),
                       
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
